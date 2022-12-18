#include<iostream>
#include<string>
#include "Source2.cpp"
using namespace std;
//class BiletCategoriaA
//{
//private:
//	int ID;
//	string locatieCinema;
//	int nrLoc;
//	int* loc;
//	bool disponibil;
//	float pretA;
//	static int contorBilete;
//public:
//	//Constructor implicit si cu parametri
//	BiletCategoriaA()
//	{
//		this->ID = ID;
//		locatieCinema = "";
//		nrLoc = 0;
//		loc = nullptr;
//		disponibil = "Y/N";
//		pretA = 0;
//	}
//	BiletCategoriaA(int ID, string locatieCinema, int nrLoc, int* loc, bool disponibil, float pretA)
//	{
//		this->ID = ID;
//		locatieCinema = "";
//		nrLoc = 0;
//		loc = nullptr;
//		disponibil = "Y/N";
//		pretA = 0;
//
//	}
//	//Constructor de copiere
//	BiletCategoriaA(const BiletCategoriaA& bilet)
//	{
//		this->ID = bilet.ID;
//		locatieCinema = "";
//		nrLoc = 0;
//		loc = nullptr;
//		disponibil = "Y/N";
//		pretA = 0;
//	}
//	//Operator egal pt membru pointer regula celor 3
//	BiletCategoriaA& operator=(const BiletCategoriaA& bilet)
//	{
//		nrLoc = 0;
//		loc = nullptr;
//		disponibil = "Y/N";
//		pretA = 0;
//		return *this;
//
//	}
//	//Setteri
//	void setID(int d)
//	{
//		ID = d;
//	}
//
//	void setLocatieCinema(string l)
//	{
//		locatieCinema = l;
//	}
//	void setNrLoc(int n)
//	{
//		nrLoc = n;
//	}
//	void setPretA(float p)
//	{
//		pretA = p;
//	}
//	void setDisponibil(bool d)
//	{
//		disponibil = d;
//	}
//	//Getteri
//	int getID()
//	{
//		return this->ID;
//	}
//
//
//	string getLocatieCinema()
//	{
//		return locatieCinema;
//	}
//
//	int getNrLoc()
//	{
//		return nrLoc;
//	}
//
//	float getPretA()
//	{
//		return pretA;
//	}
//
//	//Getter si setter pt membrul pointer
//	int* getLoc() {
//		if (loc != nullptr) {
//			int* copy = new int[nrLoc];
//			for (int i = 0; i < nrLoc; i++) {
//				copy[i] = loc[i];
//			}
//			return copy;
//		}
//		else return nullptr;
//	}
//	void setLoc(int* loc, int nrLoc) {
//		if (loc != nullptr && nrLoc > 0) {
//			delete[] this->loc;
//			this->loc = new int[nrLoc];
//			for (int i = 0; i < nrLoc; i++) {
//				this->loc[i] = loc[i];
//			}
//			this->nrLoc = nrLoc;
//		}
//	}
//
//
//	//2 metode generice
//	static long getVizionare(int contorBilete)
//	{
//		if (contorBilete < 5)
//		{
//			cout << "Vizionarea filmului nu va avea loc.";
//		}
//		return 0;
//	};
//	static long getCeleMaiBuneLocuriDinSala(int nrLoc, int nrLocMijloc)
//	{
//		nrLocMijloc = floor(nrLoc / 2);
//		if (nrLoc > nrLocMijloc)
//		{
//			cout << "Ati ales un loc cu vizibilitate optima.";
//		}
//		else
//			cout << "Selectati un alt loc.";
//	}
//
////Altele 2
//	BiletCategoriaA& operator++()
//	{
//		if (loc != nullptr && nrLoc > 0)
//		{
//			loc[0]++;
//		}
//		return *this;
//	}
//	explicit operator string()
//	{
//		return locatieCinema;
//	}
//	//Destructor daca e cazul E CAZUL
//	~BiletCategoriaA()
//	{
//		if (this->loc != nullptr)
//		{
//			delete[] this->loc;
//			this->loc = nullptr;
//		}
//	}
//};
//int BiletCategoriaA::contorBilete = 0;
//
//class BiletCategoriaB
//
//{
//	int ID;
//	string locatieCinema;
//	int nrLoc;
//	int* loc;
//	bool disponibil;
//	float pretB;
//	static int contorBilete;
//public:
//	//Constructor implicit si cu parametri
//	BiletCategoriaB()
//	{
//		this->ID = ID;
//		locatieCinema = "";
//		nrLoc = 0;
//		loc = nullptr;
//		disponibil = "Y/N";
//		pretB = 0;
//	}
//	BiletCategoriaB(int ID, string locatieCinema, int nrLoc, int* loc, bool disponibil, float pretB)
//	{
//		this->ID = ID;
//		locatieCinema = "";
//		nrLoc = 0;
//		loc = nullptr;
//		disponibil = "Y/N";
//		pretB = 0;
//
//	}
//	//Constructor de copiere
//	BiletCategoriaB(const BiletCategoriaB& bilet)
//	{
//		this->ID = bilet.ID;
//		locatieCinema = "";
//		nrLoc = 0;
//		loc = nullptr;
//		disponibil = "Y/N";
//		pretB = 0;
//	}
//	//Operator egal pt membru pointer regula celor 3
//	BiletCategoriaB& operator=(const BiletCategoriaB& bilet)
//	{
//		nrLoc = 0;
//		loc = nullptr;
//		disponibil = "Y/N";
//		pretB = 0;
//		return *this;
//
//	}
//	//Setteri
//	void setID(int d)
//	{
//		ID = d;
//	}
//
//	void setLocatieCinema(string l)
//	{
//		locatieCinema = l;
//	}
//	void setNrLoc(int n)
//	{
//		nrLoc = n;
//	}
//	void setPretB(float p)
//	{
//		pretB = p;
//	}
//	void setDisponibil(bool d)
//	{
//		disponibil = d;
//	}
//	//Getteri
//	int getID()
//	{
//		return this->ID;
//	}
//
//
//	string getLocatieCinema()
//	{
//		return locatieCinema;
//	}
//
//	int getNrLoc()
//	{
//		return nrLoc;
//	}
//
//	float getPretB()
//	{
//		return pretB;
//	}
//
//	//Getter si setter pt membrul pointer
//	int* getLoc() {
//		if (loc != nullptr) {
//			int* copy = new int[nrLoc];
//			for (int i = 0; i < nrLoc; i++) {
//				copy[i] = loc[i];
//			}
//			return copy;
//		}
//		else return nullptr;
//	}
//	void setLoc(int* loc, int nrLoc) {
//		if (loc != nullptr && nrLoc > 0) {
//			delete[] this->loc;
//			this->loc = new int[nrLoc];
//			for (int i = 0; i < nrLoc; i++) {
//				this->loc[i] = loc[i];
//			}
//			this->nrLoc = nrLoc;
//		}
//	}
//	//2 metode generice
//	static long getVizionare(int contorBilete)
//	{
//		if (contorBilete < 5)
//		{
//			cout << "Vizionarea filmului nu va avea loc.";
//		}
//		return 0;
//	};
//	static long getCeleMaiBuneLocuriDinSala(int nrLoc, int nrLocMijloc)
//	{
//		nrLocMijloc = floor(nrLoc / 2);
//		if (nrLoc > nrLocMijloc)
//		{
//			cout << "Ati ales un loc cu vizibilitate optima.";
//		}
//		else
//			cout << "Selectati un alt loc.";
//	}
//
//	//Altele 2
//	BiletCategoriaB& operator++()
//	{
//		if (loc != nullptr && nrLoc > 0)
//		{
//			loc[0]++;
//		}
//		return *this;
//	}
//	explicit operator string()
//	{
//		return locatieCinema;
//	}
//	//Destructor daca e cazul E CAZUL
//	~BiletCategoriaB()
//	{
//		if (this->loc != nullptr)
//		{
//			delete[] this->loc;
//			this->loc = nullptr;
//		}
//	}
//
//};
//int BiletCategoriaB::contorBilete = 0;
//
//	class Card
//	{
//	private:
//		float pretn;
//		bool reducerestud;
//		static float CalculPretFinal;
//	public:
//		const float reducere = 0.5;
//		Card(float pretn, bool reducerestud) :reducere(reducere)
//		{
//			pretn = 0;
//			reducerestud = "Y/N";
//		};
//
//
//		void setPretn(float n)
//		{
//			pretn = n;
//		};
//		void setReducerestud(bool r)
//		{
//			reducerestud = r;
//		};
//		float getPretn()
//		{
//			return pretn;
//		};
//		bool getReducerestud()
//		{
//			return reducerestud;
//		};
//		static long getPretulDupaReducere(float pretn, bool reducerestud, const float reducere, float pretredus)
//		{
//			if (reducerestud)
//			{
//				pretredus = pretn - 0, 5 * pretn;
//			}
//			else
//				cout << "Reducerile se aplica doar studentilor si elevilor.";
//		}
//		static long getCatAtiEconomisit(float pretn, float pretredus, bool reducerestud, float D)
//		{
//			if (reducerestud)
//			{
//				D = pretredus - pretn;
//				cout << "Ati economisit" << D << "lei." << endl;
//			}
//
//		};
//		
//	};

	int main()
	{}