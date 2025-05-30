//AVL

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 128

typedef struct FootballPlayer {
    unsigned int playerID;
    char* name;
    char* position;
    float marketValue;
} FootballPlayer;

typedef struct TreeNode {
    FootballPlayer player;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ---------- AVL Utilities ----------
int height(TreeNode* node) {
    if (!node) return 0;
    int hL = height(node->left);
    int hR = height(node->right);
    return 1 + (hL > hR ? hL : hR);
}

int getBalance(TreeNode* node) {
    if (!node) return 0;
    return height(node->right) - height(node->left);
}

void rotateLeft(TreeNode** node) {
    TreeNode* tmp = (*node)->right;
    (*node)->right = tmp->left;
    tmp->left = *node;
    *node = tmp;
}

void rotateRight(TreeNode** node) {
    TreeNode* tmp = (*node)->left;
    (*node)->left = tmp->right;
    tmp->right = *node;
    *node = tmp;
}

// ---------- AVL Insert ----------
void insert(TreeNode** root, FootballPlayer player) {
    if (!(*root)) {
        TreeNode* newNode = malloc(sizeof(TreeNode));
        newNode->player = player;
        newNode->left = newNode->right = NULL;
        *root = newNode;
        return;
    }

    if (player.playerID < (*root)->player.playerID)
        insert(&(*root)->left, player);
    else
        insert(&(*root)->right, player);

    int bf = getBalance(*root);

    if (bf == 2) {
        if (getBalance((*root)->right) >= 0)
            rotateLeft(root);
        else {
            rotateRight(&(*root)->right);
            rotateLeft(root);
        }
    }
    else if (bf == -2) {
        if (getBalance((*root)->left) <= 0)
            rotateRight(root);
        else {
            rotateLeft(&(*root)->left);
            rotateRight(root);
        }
    }
}

// ---------- Citire din fișier ----------
FootballPlayer readPlayerFromFile(FILE* f) {
    FootballPlayer player;
    char buffer[LINESIZE];

    if (fgets(buffer, LINESIZE, f)) {
        char* token = strtok(buffer, ",");
        player.playerID = atoi(token);

        token = strtok(NULL, ",");
        player.name = malloc(strlen(token) + 1);
        strcpy(player.name, token);

        token = strtok(NULL, ",");
        player.position = malloc(strlen(token) + 1);
        strcpy(player.position, token);

        token = strtok(NULL, ",");
        player.marketValue = atof(token);

        return player;
    }

    player.name = NULL;
    return player;
}

void readPlayersFromFile(TreeNode** root, const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("Eroare la deschiderea fișierului");
        return;
    }

    while (!feof(f)) {
        FootballPlayer player = readPlayerFromFile(f);
        if (player.name != NULL) {
            insert(root, player);
        }
    }

    fclose(f);
}

// ---------- Numarare după pozitie ----------
int countPlayersByPosition(TreeNode* root, const char* position) {
    if (!root) return 0;

    int count = 0;
    if (strcmp(root->player.position, position) == 0)
        count = 1;

    return count + countPlayersByPosition(root->left, position) +
        countPlayersByPosition(root->right, position);
}

// ---------- Afisare AVL ----------
void printTree(TreeNode* root, int space) {
    if (!root) return;

    space += 10;
    printTree(root->right, space);

    for (int i = 10; i < space; i++) printf(" ");
    printf("%d (%s, %s, %.2f)\n", root->player.playerID, root->player.name, root->player.position, root->player.marketValue);

    printTree(root->left, space);
}

FootballPlayer deleteNode(TreeNode** root, int id) {
    FootballPlayer deleted = { 0, NULL, NULL, 0 };

    if (!*root) return deleted;

    if (id < (*root)->player.playerID) {
        deleted = deleteNode(&(*root)->left, id);
    }
    else if (id > (*root)->player.playerID) {
        deleted = deleteNode(&(*root)->right, id);
    }
    else {
        deleted = (*root)->player;

        if (!(*root)->left || !(*root)->right) {
            TreeNode* temp = (*root)->left ? (*root)->left : (*root)->right;
            free(*root);
            *root = temp;
        }
        else {
            TreeNode* succ = (*root)->right;
            while (succ->left)
                succ = succ->left;

            (*root)->player = succ->player;
            deleteNode(&(*root)->right, succ->player.playerID);
        }
    }

    if (*root) {
        int bf = getBalance(*root);

        if (bf == 2) {
            if (getBalance((*root)->right) >= 0)
                rotateLeft(root);
            else {
                rotateRight(&(*root)->right);
                rotateLeft(root);
            }
        }
        if (bf == -2) {
            if (getBalance((*root)->left) <= 0)
                rotateRight(root);
            else {
                rotateLeft(&(*root)->left);
                rotateRight(root);
            }
        }
    }

    return deleted;
}
void deletePlayersBelowValue(TreeNode** root, float threshold) {
    if (!(*root)) return;

    // Recursiv in subarbori mai întai
    deletePlayersBelowValue(&(*root)->left, threshold);
    deletePlayersBelowValue(&(*root)->right, threshold);

    // Daca acest nod trebuie sters
    if ((*root)->player.marketValue < threshold) {
        deleteNode(root, (*root)->player.playerID);
    }
}


// ---------- Main ----------
int main() {
    TreeNode* root = NULL;

    readPlayersFromFile(&root, "players.txt");

    printf("=== AVL TREE ===\n");
    printTree(root, 0);

    printf("\nNumar jucatori pe pozitia 'Forward': %d\n", countPlayersByPosition(root, "Forward"));
    printf("Numar jucatori pe pozitia 'Midfielder': %d\n", countPlayersByPosition(root, "Midfielder"));

    printf("\nStergem jucatorii cu valoare de piata < 100.0...\n");
    deletePlayersBelowValue(&root, 100.0);
    printTree(root, 0);


    return 0;
}
//10, Messi, Forward, 150.5
//7, De Bruyne, Midfielder, 120.0
//15, Neuer, Goalkeeper, 90.5
//3, Benzema, Forward, 80.0
//12, Modric, Midfielder, 65.0
//9, Haaland, Forward, 180.0


//Heap
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura jucator
typedef struct {
    unsigned int playerID;
    char* name;
    char* position;
    float marketValue;
} FootballPlayer;

// Structura Heap
typedef struct {
    FootballPlayer* vect;
    int dim;
} Heap;

// Functie creare jucator
FootballPlayer initPlayer(unsigned int id, const char* name, const char* pos, float value) {
    FootballPlayer p;
    p.playerID = id;
    p.name = _strdup(name);
    p.position = _strdup(pos);
    p.marketValue = value;
    return p;
}

// Swap
void swap(FootballPlayer* a, FootballPlayer* b) {
    FootballPlayer tmp = *a;
    *a = *b;
    *b = tmp;
}

// Inserare in heap (max-heap dupa marketValue)
void insertHeap(Heap* h, FootballPlayer p) {
    h->vect = realloc(h->vect, (h->dim + 1) * sizeof(FootballPlayer));
    h->vect[h->dim] = p;
    int i = h->dim++;

    while (i > 0 && h->vect[(i - 1) / 2].marketValue < h->vect[i].marketValue) {
        swap(&h->vect[i], &h->vect[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Afisare jucator
void printPlayer(FootballPlayer p) {
    printf("ID: %u | Name: %s | Position: %s | Value: %.2f mil\n",
        p.playerID, p.name, p.position, p.marketValue);
}

// Afisare heap
void printHeap(Heap h) {
    for (int i = 0; i < h.dim; i++) {
        printPlayer(h.vect[i]);
    }
}

// Citire din fisier
void readFromFile(const char* filename, Heap* h) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("Eroare deschidere fisier");
        return;
    }

    unsigned int id;
    char name[50], pos[30];
    float value;

    while (fscanf(f, "%u,%[^,],%[^,],%f\n", &id, name, pos, &value) == 4) {
        FootballPlayer p = initPlayer(id, name, pos, value);
        insertHeap(h, p);
    }

    fclose(f);
}

// Numarare jucatori pe o pozitie
int countPosition(Heap h, const char* poz) {
    int count = 0;
    for (int i = 0; i < h.dim; i++) {
        if (strcmp(h.vect[i].position, poz) == 0)
            count++;
    }
    return count;
}

// Eliberare heap
void freeHeap(Heap* h) {
    for (int i = 0; i < h->dim; i++) {
        free(h->vect[i].name);
        free(h->vect[i].position);
    }
    free(h->vect);
}

// Functie eliminare jucatori cu marketValue sub o valoare data
void removePlayersBelowValue(Heap* h, float minValue) {
    int newDim = 0;
    for (int i = 0; i < h->dim; i++) {
        if (h->vect[i].marketValue >= minValue) {
            // pastreaza jucatorul
            h->vect[newDim++] = h->vect[i];
        }
        else {
            // elibereaza memoria jucatorilor eliminati
            free(h->vect[i].name);
            free(h->vect[i].position);
        }
    }
    h->vect = realloc(h->vect, newDim * sizeof(FootballPlayer));
    h->dim = newDim;
}

int main() {
    Heap h = { .vect = NULL, .dim = 0 };
    readFromFile("players.txt", &h);

    printf("=== HEAP INAINTE DE FILTRARE ===\n");
    printHeap(h);

    

    printf("\nNumar de jucatori pe pozitia 'Forward': %d\n", countPosition(h, "Forward"));

    // Sterge jucatorii cu marketValue sub 10 milioane
    removePlayersBelowValue(&h, 100.0f);

    printf("\n=== HEAP DUPA FILTRARE (marketValue >= 10) ===\n");
    printHeap(h);

    freeHeap(&h);
    return 0;
}
//10, Messi, Forward, 150.5
//7, De Bruyne, Midfielder, 120.0
//15, Neuer, Goalkeeper, 90.5
//3, Benzema, Forward, 80.0
//12, Modric, Midfielder, 65.0
//9, Haaland, Forward, 180.0
