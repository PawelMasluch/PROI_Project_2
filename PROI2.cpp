// Pawel Masluch, nr albumu 262955
#include<iostream>
#include<string>
#include<vector>
#include<fstream>


using namespace std;


ofstream Debugger("Debugger.txt"); // Debugger.txt - plik z informacjami do pozniejszego debuggowania - tworzenie, usuwanie i kopiowanie obiektow.


/** Dostarcza funkcjonalnosci dla klas Student oraz Teacher. */

class Person /// Klasa reprezentujaca osobe.
{
	protected:
		string name; ///< Imie.
		string surname; ///< Nazwisko.
		string PESEL; ///< Numer PESEL.
	
	public:
		
		/**
		 * @param n - Imie.
		 * @param s - Nazwisko.
		 * @param P - PESEL.
		 */
		
		Person(string n="Jan", string s="Kowalski", string P="00000000000") /// Publiczny konstruktor.
		{
			name = n;
			surname = s;
			PESEL = P;
			
			Debugger << "\nStworzono obiekt klasy Person\n";
		}
		
		~Person() /// Publiczny destruktor.
		{
			Debugger << "\nUsunieto obiekt klasy Person\n";
		}
		
		Person(const Person &x) /// Konstruktor kopiujacy.
		{
			PESEL = x.PESEL;
			name = x.name;
			surname = x.surname;
			
			Debugger << "\nSkopiowano obiekt klasy Person\n";
	    }
		
		
		/**
		 * @return bool - czy porownywane osoby to tak naprawde ta sama osoba - jesli tak - zwracamy true, w przeciwnym wypadku false.
		 */
		
		bool operator ==(Person &x) /// Operator porownujacy 2 osoby.
		{
			return ( PESEL == x.PESEL  &&  name == x.name  &&  surname == x.surname );
		}
		
		
		/** Wirtualna metoda dla klas pochodnych (Student, Teacher). */
		
		virtual void input() /// Metoda do wczytywania atrybutow osoby z konsoli.
		{
			cout << "\nPodaj PESEL: ";
			cin >> PESEL;
			cout << "Podaj imie: ";
			cin >> name;
			cout << "Podaj nazwisko: ";
			cin >> surname;
		}
		
		
		/** Wirtualna metoda dla klas pochodnych (Student, Teacher). */
		
		virtual void output() /// Metoda do wypisania atrybutow osoby do konsoli.
		{
			cout << "\nPESEL: " << PESEL << "\nImie: " << name << "\nNazwisko: " << surname << "\n";
		}
};



/** Dziedziczy publicznie z klasy Person. */

class Student :public Person /// Klasa reprezuntujaca ucznia.
{
	public:
		
		
		/**
		 * @param n - Imie.
		 * @param s - Nazwisko.
		 * @param P - PESEL.
		 */
		
		Student(string n="Jan", string s="Kowalski", string P="00000000000") /// Publiczny konstruktor.
		:Person(n,s,P)
		{
			Debugger << "\nStworzono obiekt klasy Student\n";
		}
		
		~Student() /// Publiczny destruktor.
		{
			Debugger << "\nUsunieto obiekt klasy Student\n";
		}
		
		Student(const Student &x) /// Konstruktor kopiujacy. 
		:Person()
		{
			PESEL = x.PESEL;
			name = x.name;
			surname = x.surname;
			
			Debugger << "\nSkopiowano obiekt klasy Student\n";
	    }
		
		
		/**
		 * @return bool - czy porownywani ucznowie to tak naprawde ten sam uczen - jesli tak - zwracamy true, w przeciwnym wypadku false.
		 */
		
		bool operator ==(Student &x) /// Operator porownujacy 2 uczniow.
		{
			return ( PESEL == x.PESEL  &&  name == x.name  &&  surname == x.surname );
		}
		
		
		/** Specjalizacja wirtualnej metody "input" z klasy Person. */
		
		virtual void input() /// Wczytanie atrybutow ucznia z konsoli.
		{
			cout << "\nWprowadz dane ucznia:";
			Person::input();
		}
		
		
		/** Specjalizacja wirtualnej metody "output" z klasy Person. */
		
		virtual void output() /// Wypisanie atrybutow ucznia do konsoli.
		{
			cout << "\nWypisuje dane ucznia:";
			Person::output();
		}
		
		ostream & operator >> (ostream &out) /// Wypisanie atrybutow ucznia do strumienia wyjsciowego.
		{
			return out << "\nDane ucznia:\n" << "PESEL: " << PESEL << "\nImie: " << name << "\nNazwisko: " << surname << endl;
		}
		
		istream & operator << (istream &in) /// Wczytanie atrybutow ucznia ze strumienia wejsciowego.
		{
			return in >> PESEL >> name >> surname;
		}
};



/** Dziedziczy publicznie z klasy Person. */

class Teacher :public Person /// Klasa reprezentujaca nauczyciela.
{
	protected:
		int experience; ///< Doswiadczenie (w latach) w nauczaniu.
		
	public:
		
		
		/**
		 * @param n - Imie.
		 * @param s - Nazwisko.
		 * @param P - PESEL.
		 * @param e - Doswiadczenie (w latach) w nauczaniu.
		 */
		
		Teacher(string n="Jan", string s="Kowalski", string P="00000000000", int e=0) /// Publiczny konstruktor.
		:Person(n,s,P)
		{
			experience = e;
			
			Debugger << "\nStworzono obiekt klasy Teacher\n";
		}
		
		~Teacher() /// Publiczny destruktor.
		{
			Debugger << "\nUsunieto obiekt klasy Teacher\n";
		}
		
		Teacher(const Teacher &x) /// Konstruktor kopiujacy.
		:Person()
		{
			PESEL = x.PESEL;
			name = x.name;
			surname = x.surname;
			experience = x.experience;
			
			Debugger << "\nSkopiowano obiekt klasy Teacher\n";
	    }
		
		
		/**
		 * @return bool - czy porownywani nauczyciele to tak naprawde ten sam nauczyciel - jesli tak - zwracamy true, w przeciwnym wypadku false.
		 */
		
		bool operator ==(Teacher &x) /// Operator porownujacy 2 nauczycieli.
		{
			return ( PESEL == x.PESEL  &&  name == x.name  &&  surname == x.surname  &&  experience == x.experience );
		} 
		
		
		/** Specjalizacja wirtualnej metody "input" z klasy Person. */
		
		virtual void input() /// Wczytanie atrybutow nauczyciela z konsoli.
		{
			cout << "\nWprowadz dane nauczyciela:";
			Person::input();
			cout << "Podaj doswiadczenie (w latach): ";
			cin >> experience;
		}
		
		
		/** Specjalizacja wirtualnej metody "output" z klasy Person. */
		
		virtual void output() /// Wypisanie atrybutow nauczyciela do konsoli.
		{
			cout << "\nWypisuje dane nauczyciela:";
			Person::output();
			cout << "Doswiadczenie (w latach): " << experience << endl;
		}
		
		ostream & operator >> (ostream &out) /// Wypisanie atrybutow nauczyciela do strumienia wyjsciowego.
		{
			return out << "\nDane nauczyciela:\n" << "PESEL: " << PESEL << "\nImie: " << name << "\nNazwisko: " << surname << "\nDoswiadczenie (w latach): " << experience << endl;
		}
		
		istream & operator << (istream &in) /// Wczytanie atrybutow nauczyciela ze strumienia wejsciowego.
		{
			return in >> PESEL >> name >> surname >> experience;
		}
};




class Equipment /// Klasa reprezentujaca sprzet narciarski.
{
	protected:
		string size; ///< Rozmiar.
		string color; ///< Kolor.
		string manufacturer; ///< Producent.
		
	public:
		
		
		/**
		 * @param s - Rozmiar.
		 * @param c - Kolor.
		 * @param m - Producent.
		 */
		
		Equipment(string s="0", string c="brak", string m="brak") /// Publiczny konstruktor.
		{
			size = s;
			color = c;
			manufacturer = m;
			
			Debugger << "\nStworzono obiekt klasy Equipment\n";
		}
		
		~Equipment() /// Publiczny destruktor.
		{
			Debugger << "\nUsunieto obiekt klasy Equipment\n";
		}
		
		Equipment(const Equipment &x) /// Konstruktor kopiujacy.
		{
			size = x.size;
			color = x.color;
			manufacturer = x.manufacturer;
			
			Debugger << "\nSkopiowano obiekt klasy Equipment\n";
	    }
	    
	    
		/**
		 * @return bool - czy porownywane sprzety to tak naprawde ten sam sprzet - jesli tak - zwracamy true, w przeciwnym wypadku false.
		 */
		
		bool operator ==(Equipment &x) /// Operator porownujacy 2 sprzety.
		{
			return ( size == x.size  &&  color == x.color  &&  manufacturer == x.manufacturer );
		}
		
		void input() /// Wczytanie atrybutow sprzetu z konsoli.
		{
			cout << "\nWprowadz dane sprzetu:\nPodaj rozmiar: ";
			cin >> size;
			cout << "Podaj kolor: ";
			cin >> color;
			cout << "Podaj producenta: ";
			cin >> manufacturer;
			cout << "\n";
		}
		
		void output() /// Wypisanie atrybutow sprzetu do konsoli.
		{
			cout << "\nWypisuje dane sprzetu:\nRozmiar: " << size << "\nKolor: " << color << "\nProducent: " << manufacturer << "\n";
		}
		
		ostream & operator >> (ostream &out) /// Wypisanie atrybutow sprzetu do strumienia wyjsciowego.
		{
			return out << "\nDane sprzetu:\n" << "Rozmiar: " << size << "\nKolor: " << color << "\nProducent: " << manufacturer << endl;
		}
		
		istream & operator << (istream &in) /// Wczytanie atrybutow sprzetu ze strumienia wejsciowego.
		{
			return in >> size >> color >> manufacturer;
		}
};




/** Dostarcza ona funkcjonalnosci klasom PublicSchool, PrivateSchool oraz SkiSchool. */

class School /// Klasa reprezentujaca szkole.
{
	protected:
		string location; ///< Lokalizacja szkoly.
		int established; ///< Rok powstania szkoly.
		
		int NumberOfStudents; ///< Liczba uczniow w szkole.
		vector <Student> ListOfStudents; ///< Lista uczniow w szkole.
		
		int NumberOfTeachers; ///< Liczba nauczycieli w szkole
		vector <Teacher> ListOfTeachers; ///< Lista nauczycieli w szkole.
		
	public:
		
		
		/** Poczatkowo, w szkole nie ma uczniow i nauczycieli.
		 * @param l - Lokalizacja.
		 * @param e - Rok powstania.
		 */
	 	
		School(string l="Mars", int e=966) /// Publiczny konstruktor.
		{
			location = l;
			established = e;
			NumberOfStudents = 0;
			NumberOfTeachers = 0;
			
			Debugger << "\nStworzono obiekt klasy School\n";
		}
		
		
		~School() /// Publiczny destruktor.
		{
			Debugger << "\nUsunieto obiekt klasy School\n";
		}
		
		
		School(const School &S) /// Konstruktor kopiujacy.
		{
			location = S.location;
			established = S.established;
			
			
			
			NumberOfStudents = S.NumberOfStudents;
			
			ListOfStudents.clear();
			for(int i=0; i<NumberOfStudents; ++i)
			{
				ListOfStudents.push_back( S.ListOfStudents[i] );
			}
			
			
			
			NumberOfTeachers = S.NumberOfTeachers;
			
			ListOfTeachers.clear();
			for(int i=0; i<NumberOfTeachers; ++i)
			{
				ListOfTeachers.push_back( S.ListOfTeachers[i] );
			}
			
			
			
			Debugger << "\nSkopiowano obiekt klasy School\n";
		}
		
		
		/** @param x - Uczen, ktorego dodajemy do szkoly. */
		
		School & operator +=(Student &x) /// Dodawanie ucznia do szkoly.
		{
			++NumberOfStudents;
			ListOfStudents.push_back(x);
			
			Debugger << "\nDodano ucznia do szkoly\n";
			
			return *this;
		}
		
		
		/** @param x - Uczen, ktorego usuwamy ze szkoly. */
		
		School & operator -=(Student &x) /// Usuwanie ucznia ze szkoly.
		{
			bool deleted = false; // jak na razie nie usunieto ucznia ze szkoly
			
			for(vector <Student>:: iterator it=ListOfStudents.begin(); it!=ListOfStudents.end() && deleted==false; ++it)
			{
				if( (*it) == x )
				{
					swap( (*it), ListOfStudents.back() );
					ListOfStudents.pop_back();
					--NumberOfStudents;
					deleted = true;
					
					
					Debugger << "\nUsunieto ucznia ze szkoly\n";
				}
			}
			
			if(deleted == false) // jesli nie usunieto ucznia ze szkoly
			{
				Debugger << "\nPodany uczen nie figuruje na liscie uczniow\n";
			}
			
			return *this;
		}
		
		
		/** @param x - Nauczyciel, ktorego dodajemy do szkoly. */
		
		School & operator +=(Teacher &x) /// Dodawanie nauczyciela do szkoly.
		{
			++NumberOfTeachers;
			ListOfTeachers.push_back(x);
			
			
			Debugger << "\nDodano nauczyciela do szkoly\n";
			
			
			return *this;
		}
		
		
		/** @param x - Nauczyciel, ktorego usuwamy ze szkoly. */
		
		School & operator -=(Teacher &x) /// Usuwanie nauczyciela ze szkoly.
		{
			bool deleted = false; // jak na razie nie usunieto nauczyciela ze szkoly
			
			for(vector <Teacher>:: iterator it=ListOfTeachers.begin(); it!=ListOfTeachers.end() && deleted==false; ++it)
			{
				if( (*it) == x )
				{
					swap( (*it), ListOfTeachers.back() );
					ListOfTeachers.pop_back();
					--NumberOfTeachers;
					deleted = true;
					
					
					Debugger << "\nUsunieto nauczyciela ze szkoly\n";
				}
			}
			
			if(deleted == false) // jesli nie usunieto nauczyciela ze szkoly
			{
				Debugger << "\nPodany nauczyciel nie figuruje na liscie nauczycieli\n";
			}
			
			return *this;
		}
		
		
		/** Pomocnicza metoda do wypisywania informacji o szkole do konsoli. */
		
		void output1() /// Wypisywanie do konsoli lokalizacji i roku powstania szkoly.
		{
			cout << "\nLokalizacja: " << location;
			cout << "\nRok powstania: " << established;
		}
		
		
		/** Pomocnicza metoda do wypisywania informacji o szkole do konsoli. */
		
		void output2() /// Wypisywanie liczby uczniow, listy uczniow, liczby nauczycieli i listy nauczycieli w szkole.
		{
			cout << "\n\nLiczba uczniow: " << NumberOfStudents << "\n";
			for(vector <Student>:: iterator it=ListOfStudents.begin(); it!=ListOfStudents.end(); ++it)
			{
				(*it).output();
			}
			
			cout << "\n\nLiczba nauczycieli: " << NumberOfTeachers << "\n";
			for(vector <Teacher>:: iterator it=ListOfTeachers.begin(); it!=ListOfTeachers.end(); ++it )
			{
				(*it).output();
			}
		}
		
		
		 /** Wirtualna metoda dla klas pochodnych (PublicSchool, PrivateSchool, SkiSchool). */
		
		virtual void output() /// Wypisanie atrybutow szkoly do konsoli.
		{
			cout << "\nWypisuje informacje o szkole:\n";
			output1();
			output2();
		}
};




/** Dziedziczy ona publicznie z klasy School. */

class PublicSchool :public School /// Klasa reprezentujaca szkole publiczna.
{
	protected:
		string patron; ///< Patron szkoly.
		
	public:
		
		
		/** Poczatkowo, w szkole publicznej nie ma uczniow i nauczycieli.
		 * @param l - Lokalizacja.
		 * @param e - Rok powstania.
		 * @param p - Patron szkoly publicznej. 
		 */
		
		PublicSchool(string l="Mars", int e=966, string p="Papa_Smerf") /// Publiczny konstruktor.
		:School(l,e)
		{
			patron = p;
			
			Debugger << "\nStworzono obiekt klasy PublicSchool\n";
		}
		
		
		~PublicSchool() /// Publiczny destruktor.
		{
			Debugger << "\nUsunieto obiekt klasy PublicSchool\n";
		}
		
		
		PublicSchool(const PublicSchool &S) /// Konstruktor kopiujacy.
		:School()
		{
			location = S.location;
			established = S.established;
			patron = S.patron;
			
			
			
			NumberOfStudents = S.NumberOfStudents;
			
			ListOfStudents.clear();
			for(int i=0; i<NumberOfStudents; ++i)
			{
				ListOfStudents.push_back( S.ListOfStudents[i] );
			}
			
			
			
			NumberOfTeachers = S.NumberOfTeachers;
			
			ListOfTeachers.clear();
			for(int i=0; i<NumberOfTeachers; ++i)
			{
				ListOfTeachers.push_back( S.ListOfTeachers[i] );
			}
			
			
			
			
			Debugger << "\nSkopiowano obiekt klasy PublicSchool\n";
		}
		
		
		/** Specjalizacja metody wirtualnej "output" z klasy School. */
		
		virtual void output() /// Wypisanie atrybutow szkoly publicznej do konsoli.
		{
			cout << "\n\nWypisuje informacje o szkole publicznej:";
			School::output1();
			cout << "\nPatron: " << patron;
			School::output2();
		}
		
		
		ostream & operator >> (ostream &out) /// Wypisanie informacji o szkole publicznej do strumienia wyjsciowego.
		{
			out << "\n\nDane szkoly publicznej:\n" << "Lokalizacja: " << location << "\nRok powstania: " << established << "\nPatron: " << patron << endl << endl;
			
			
			
			
			out << "Liczba uczniow: " << NumberOfStudents << endl << endl;
			out << "Lista uczniow:\n";
			
			for(int i=0; i<NumberOfStudents; ++i)
			{
				ListOfStudents[i] >> out;
				
				out << endl;
			}
			
			
			
			
			out << "\n\nLiczba nauczycieli: " << NumberOfTeachers << endl << endl;
			out << "Lista nauczycieli:\n";
			
			for(int i=0; i<NumberOfTeachers; ++i)
			{
				ListOfTeachers[i] >> out;
				
				out << endl;
			}
			
			
			
			
			return out;
		}
		
		
		istream & operator << (istream &in) /// Wczytanie informacji o szkole publicznej (lokalizacji, roku powstania i patrona) ze strumienia wejsciowego.
		{
			return in >> location >> established >> patron;
		}
};



/** Dziedziczy ona publicznie z klasy School. */

class PrivateSchool :public School /// Klasa reprezentujaca szkole prywatna.
{
	protected:
		int PricePerHour; ///< Cena za godzine zajec.
		
	public:
		
		
		/** Poczatkowo, w szkole prywatnej nie ma uczniow i nauczycieli.
		 * @param l - Lokalizacja.
		 * @param e - Rok powstania.
		 * @param p - Cena za godzine zajec. 
		 */
		
		PrivateSchool(string l="Mars", int e=966, int p=0) /// Publiczny konstruktor.
		:School(l,e)
		{
			PricePerHour = p;
			
			Debugger << "\nStworzono obiekt klasy PrivateSchool\n";
		}
		
		
		~PrivateSchool() /// Publiczny destruktor.
		{
			Debugger << "\nUsunieto obiekt klasy PrivateSchool\n";
		}
		
		
		PrivateSchool(const PrivateSchool &S) /// Konstruktor kopiujacy.
		:School()
		{
			location = S.location;
			established = S.established;
			PricePerHour = S.PricePerHour;
			
			
			
			NumberOfStudents = S.NumberOfStudents;
			
			ListOfStudents.clear();
			for(int i=0; i<NumberOfStudents; ++i)
			{
				ListOfStudents.push_back( S.ListOfStudents[i] );
			}
			
			
			
			NumberOfTeachers = S.NumberOfTeachers;
			
			ListOfTeachers.clear();
			for(int i=0; i<NumberOfTeachers; ++i)
			{
				ListOfTeachers.push_back( S.ListOfTeachers[i] );
			}
			
			
			
			
			Debugger << "\nSkopiowano obiekt klasy PrivateSchool\n";
		}
		
		
		/** Specjalizacja metody wirtualnej "output" z klasy School. */
		
		virtual void output() /// Wypisanie informacji o szkole prywatnej do konsoli. 
		{
			cout << "\n\nWypisuje informacje o szkole prywatnej:";
			School::output1();
			cout << "\nCena za godzine: " << PricePerHour;
			School::output2();
		}
		
		
		ostream & operator >> (ostream &out) /// Wypisanie informacji o szkole prywatnej do strumienia wyjsciowego.
		{
			out << "\n\nDane szkoly prywatnej:\n" << "Lokalizacja: " << location << "\nRok powstania: " << established << "\nCena za godzine: " << PricePerHour << endl << endl;
			
			
			
			out << "Liczba uczniow: " << NumberOfStudents << endl << endl;
			out << "Lista uczniow:\n";
			
			for(int i=0; i<NumberOfStudents; ++i)
			{
				ListOfStudents[i] >> out;
				
				out << endl;
			}
			
			
			
			out << "\n\nLiczba nauczycieli: " << NumberOfTeachers << endl << endl;
			out << "Lista nauczycieli:\n";
			
			for(int i=0; i<NumberOfTeachers; ++i)
			{
				ListOfTeachers[i] >> out;
				
				out << endl;
			}
			
			
			
			
			return out;
		}
		
		
		istream & operator << (istream &in) /// Wczytanie informacji o szkole prywatnej (lokalizaja, rok powstania, cena za godzine zajec) ze strumienia wejsciowego.
		{
			return in >> location >> established >> PricePerHour;
		}
};



/** Dziedziczy ona publicznie z klasy PrivateSchool. */

class SkiSchool :public PrivateSchool /// Klasa reprezentujaca szkole narciarska.
{
	protected:
		int NumberOfEquipment; ///< Liczba sprzetu.
		vector < Equipment > ListOfEquipment; ///< Lista sprzetu.
		
	public:
		
		
		/** Poczatkowo, w szkole narciarskiej nie ma uczniow, nauczycieli i sprzetu.
		 * @param l - Lokalizacja.
		 * @param e - Rok powstania.
		 * @param p - Cena za godzine zajec. 
		 */
		
		SkiSchool(string l="Mars", int e=966, int p=0) /// Publiczny konstruktor.
		:PrivateSchool(l,e,p)
		{
			NumberOfEquipment = 0;
			
			Debugger << "\nStworzono obiekt klasy SkiSchool\n";
		}
		
		
		~SkiSchool() /// Publiczny destruktor.
		{
			Debugger << "\nUsunieto obiekt klasy SkiSchool\n";
		}
		
		
		SkiSchool(const SkiSchool &S) /// Konstruktor kopiujacy.
		:PrivateSchool()
		{
			location = S.location;
			established = S.established;
			PricePerHour = S.PricePerHour;
			
			
			
			
			NumberOfStudents = S.NumberOfStudents;
			
			ListOfStudents.clear();
			for(int i=0; i<NumberOfStudents; ++i)
			{
				ListOfStudents.push_back( S.ListOfStudents[i] );
			}
			
			
			
			NumberOfTeachers = S.NumberOfTeachers;
			
			ListOfTeachers.clear();
			for(int i=0; i<NumberOfTeachers; ++i)
			{
				ListOfTeachers.push_back( S.ListOfTeachers[i] );
			}
			
			
			
			NumberOfEquipment = S.NumberOfEquipment;
			
			ListOfEquipment.clear();
			for(int i=0; i<NumberOfEquipment; ++i)
			{
				ListOfEquipment.push_back( S.ListOfEquipment[i] );
			}
			
			
			
			Debugger << "\nSkopiowano obiekt klasy SkiSchool\n";
		}
		
		
		/**
		 * @param x - Sprzet, ktory dodajemy do szkoly narciarskiej. 
		*/
		
		SkiSchool & operator +=(Equipment &x) /// Dodawanie sprzetu do szkoly narciarskiej.
		{
			++NumberOfEquipment;
			ListOfEquipment.push_back(x);
			
			
			Debugger << "\nDodano sprzet do szkoly\n";
			
			
			return *this;
		}
		
		
		/**
		 * @param x - Sprzet, ktory usuwamy ze szkoly narciarskiej. 
		*/
		
		SkiSchool & operator -=(Equipment &x) /// Usuwanie sprzetu ze szkoly narciarskiej.
		{
			bool deleted = false; // jak na razie nie usunieto sprzetu ze szkoly
			
			for(vector <Equipment>:: iterator it=ListOfEquipment.begin(); it!=ListOfEquipment.end() && deleted==false; ++it)
			{
				if( (*it) == x )
				{
					swap( (*it), ListOfEquipment.back() );
					ListOfEquipment.pop_back();
					--NumberOfEquipment;
					deleted = true;
					
					
					Debugger << "\nUsunieto sprzet ze szkoly\n";
				}
			}
			
			if(deleted == false) // jesli nie usunieto sprzetu ze szkoly
			{
				Debugger << "\nPodany sprzet nie figuruje na liscie sprzetu\n";
			}
			
			return *this;
		}
		
		
		/** Specjalizacja metody "output" z klasy School. */
		
		virtual void output() /// Wypisywanie atrybutow szkoly narciarskiej do konsoli.
		{
			cout << "\n\nWypisuje informacje o szkole narciarskiej:";
			School::output1();
			cout << "\nCena za godzine: " << PricePerHour;
			School::output2();
			cout << "\n\nLiczba sprzetu: " << NumberOfEquipment << "\n";
			for(vector <Equipment>:: iterator it=ListOfEquipment.begin(); it!=ListOfEquipment.end(); ++it )
			{
				(*it).output();
			}
		}
		
		
		ostream & operator >> (ostream &out) /// Wypisywanie atrybutow szkoly narciarskiej do strumienia wyjsciowego.
		{
			out << "\n\nDane szkoly narciarskiej:\n" << "Lokalizacja: " << location << "\nRok powstania: " << established << "\nCena za godzine: " << PricePerHour << endl << endl;
			
			
			
			out << "Liczba uczniow: " << NumberOfStudents << endl << endl;
			out << "Lista uczniow:\n";
			
			for(int i=0; i<NumberOfStudents; ++i)
			{
				ListOfStudents[i] >> out;
				
				out << endl;
			}
			
			
			
			out << "\n\nLiczba nauczycieli: " << NumberOfTeachers << endl << endl;
			out << "Lista nauczycieli:\n";
			
			for(int i=0; i<NumberOfTeachers; ++i)
			{
				ListOfTeachers[i] >> out;
				
				out << endl;
			}
			
			
			
			
			out << "\n\nLiczba sprzetu: " << NumberOfEquipment << endl << endl;
			out << "Lista sprzetu:\n";
			
			for(int i=0; i<NumberOfEquipment; ++i)
			{
				ListOfEquipment[i] >> out;
				
				out << endl;
			}
			
			
			
			
			return out;
		}
		
		
		istream & operator << (istream &in) /// Wczytywanie atrybutow szkoly narciarskiej (lokalizacja, rok powstania, cena za godzine zajec) ze strumienia wejsciowego.
		{
			return in >> location >> established >> PricePerHour;
		}
};




void Simulate() // Symulujemy (wedlug ustalonego scenariusza) dzialanie zaprojektowanych klas.
{
	// 1) Wczytanie podstawowych informacji o szkole publicznej
	
	Debugger << "\nFaza 1\n";
	
	PublicSchool PuS;
	
	ifstream PuS_IN("PuS_IN.txt");
	PuS << PuS_IN;
	PuS_IN.close();
	
	
	
	
	// 2) Wczytanie podstawowych informacji o szkole prywatnej
	
	Debugger << "\nFaza 2\n";
	
	PrivateSchool PrS;
	
	ifstream PrS_IN("PrS_IN.txt");
	PrS << PrS_IN;
	PrS_IN.close();
	
	
	
	
	// 3) Wczytanie podstawowych informacji o szkole narciarskiej
	
	Debugger << "\nFaza 3\n";
	
	SkiSchool SS;
	
	ifstream SS_IN("SS_IN.txt");
	SS << SS_IN;
	SS_IN.close();
	
	
	
	
	// 4) Stworzenie tablicy polimorficznych wskaznikow na szkoly
	
	Debugger << "\nFaza 4\n";
	
	School **A = new School * [3];
	
	
	
	// 5) Przyporzadkowanie wskaznikom poszczegolnych szkol
	
	Debugger << "\nFaza 5\n";
	
	A[0] = &PuS;
	A[1] = &PrS;
	A[2] = &SS;
	
	
	
	// 6) Zmienne pomocnicze
	
	Debugger << "\nFaza 6\n";
	
	int n;
	Teacher T;
	Student S;
	Equipment E;
	
	
	
	
	
	// Operacje dla szkoly publicznej
	
	
	// 7) Dodanie nauczycieli do szkoly publicznej
	
	Debugger << "\nFaza 7\n";
	
	ifstream PuS_Teachers_In("PuS_Teachers_In.txt");
	PuS_Teachers_In >> n; // wczytanie do zmiennej n liczby nauczycieli do dodania
	for(int i=0; i<n; ++i)
	{
		T << PuS_Teachers_In; // wczytanie nauczyciela
		
		(*A[0]) += T; // dodanie nauczyciela
	}
	PuS_Teachers_In.close();
	
	
	
	// 8) Dodanie uczniow do szkoly publicznej
	
	Debugger << "\nFaza 8\n";
	
	ifstream PuS_Students_In("PuS_Students_In.txt");
	PuS_Students_In >> n; // wczytanie do zmiennej n liczby uczniow do dodania
	for(int i=0; i<n; ++i)
	{
		S << PuS_Students_In; // wczytanie ucznia
		
		(*A[0]) += S; // dodanie ucznia
	}
	PuS_Students_In.close();
	
	
	
	// 9) Wypisanie informacji o szkole publicznej
	
	Debugger << "\nFaza 9\n";
	cout << "\nFaza 9\n";
	
	ofstream PuS_OUT1("PuS_OUT1.txt");
	PuS >> PuS_OUT1;
	PuS_OUT1.close();
	
	(*A[0]).output();
	
	
	
	// 10) Usuniecie nauczycieli ze szkoly publicznej
	
	Debugger << "\nFaza 10\n";
	
	ifstream PuS_Teachers_Out("PuS_Teachers_Out.txt");
	PuS_Teachers_Out >> n; // wczytanie do zmiennej n liczby nauczycieli do usuniecia
	for(int i=0; i<n; ++i)
	{
		T << PuS_Teachers_Out; // wczytanie nauczyciela
		
		(*A[0]) -= T; // usuniecie nauczyciela
	}
	PuS_Teachers_Out.close();
	
	
	
	// 11) Usuniecie uczniow ze szkoly publicznej
	
	Debugger << "\nFaza 11\n";
	
	ifstream PuS_Students_Out("PuS_Students_Out.txt");
	PuS_Students_Out >> n; // wczytanie do zmiennej n liczby do usuniecia
	for(int i=0; i<n; ++i)
	{
		S << PuS_Students_Out; // wczytanie ucznia
		
		(*A[0]) -= S; // usuniecie ucznia
	}
	PuS_Students_Out.close();
	
	
	
	// 12) Wypisanie informacji o szkole publicznej
	
	Debugger << "\nFaza 12\n";
	cout << "\nFaza 12\n";
	
	ofstream PuS_OUT2("PuS_OUT2.txt");
	PuS >> PuS_OUT2;
	PuS_OUT2.close();
	
	(*A[0]).output();
	
	
	
	
	
	
	
	
	// Operacje dla szkoly prywatnej
	
	
	// 13) Dodanie nauczycieli do szkoly prywatnej
	
	Debugger << "\nFaza 13\n";
	
	ifstream PrS_Teachers_In("PrS_Teachers_In.txt");
	PrS_Teachers_In >> n; // wczytanie do zmiennej n liczby nauczycieli do dodania
	for(int i=0; i<n; ++i)
	{
		T << PrS_Teachers_In; // wczytanie nauczyciela
		
		(*A[1]) += T; // dodanie nauczyciela
	}
	PrS_Teachers_In.close();
	
	
	
	// 14) Dodanie uczniow do szkoly prywatnej
	
	Debugger << "\nFaza 14\n";
	
	ifstream PrS_Students_In("PrS_Students_In.txt");
	PrS_Students_In >> n; // wczytanie do zmiennej n liczby uczniow do dodania
	for(int i=0; i<n; ++i)
	{
		S << PrS_Students_In; // wczytanie ucznia
		
		(*A[1]) += S; // dodanie ucznia
	}
	PrS_Students_In.close();
	
	
	
	// 15) Wypisanie informacji o szkole prywatnej
	
	Debugger << "\nFaza 15\n";
	cout << "\nFaza 15\n";
	
	ofstream PrS_OUT1("PrS_OUT1.txt");
	PrS >> PrS_OUT1;
	PrS_OUT1.close();
	
	(*A[1]).output();
	
	
	
	// 16) Usuniecie nauczycieli ze szkoly prywatnej
	
	Debugger << "\nFaza 16\n";
	
	ifstream PrS_Teachers_Out("PrS_Teachers_Out.txt");
	PrS_Teachers_Out >> n; // wczytanie do zmiennej n liczby nauczycieli do usuniecia
	for(int i=0; i<n; ++i)
	{
		T << PrS_Teachers_Out; // wczytanie nauczyciela
		
		(*A[1]) -= T; // usuniecie nauczyciela
	}
	PrS_Teachers_Out.close();
	
	
	
	// 17) Usuniecie uczniow ze szkoly prywatnej
	
	Debugger << "\nFaza 17\n";
	
	ifstream PrS_Students_Out("PrS_Students_Out.txt");
	PrS_Students_Out >> n; // wczytanie do zmiennej n liczby do usuniecia
	for(int i=0; i<n; ++i)
	{
		S << PrS_Students_Out; // wczytanie ucznia
		
		(*A[1]) -= S; // usuniecie ucznia
	}
	PrS_Students_Out.close();
	
	
	
	// 18) Wypisanie informacji o szkole prywatnej
	
	Debugger << "\nFaza 18\n";
	cout << "\nFaza 18\n";
	
	ofstream PrS_OUT2("PrS_OUT2.txt");
	PrS >> PrS_OUT2;
	PrS_OUT2.close();
	
	(*A[1]).output();
	
	
	
	
	
	
	
	
	
	
	// Operacje dla szkoly narciarskiej
	
	
	// 19) Dodanie nauczycieli do szkoly narciarskiej
	
	Debugger << "\nFaza 19\n";
	
	ifstream SS_Teachers_In("SS_Teachers_In.txt");
	SS_Teachers_In >> n; // wczytanie do zmiennej n liczby nauczycieli do dodania
	for(int i=0; i<n; ++i)
	{
		T << SS_Teachers_In; // wczytanie nauczyciela
		
		(*A[2]) += T; // dodanie nauczyciela
	}
	SS_Teachers_In.close();
	
	
	
	
	// 20) Dodanie uczniow do szkoly narciarskiej
	
	Debugger << "\nFaza 20\n";
	
	ifstream SS_Students_In("SS_Students_In.txt");
	SS_Students_In >> n; // wczytanie do zmiennej n liczby uczniow do dodania
	for(int i=0; i<n; ++i)
	{
		S << SS_Students_In; // wczytanie ucznia
		
		(*A[2]) += S; // dodanie ucznia
	}
	SS_Students_In.close();
	
	
	
	// 21) Dodanie sprzetu do szkoly narciarskiej
	
	Debugger << "\nFaza 21\n";
	
	ifstream SS_Equipment_In("SS_Equipment_In.txt");
	SS_Equipment_In >> n; // wczytanie do zmiennej n liczby sprzetu do dodania
	for(int i=0; i<n; ++i)
	{
		E << SS_Equipment_In; // wczytanie sprzetu
		
		SS += E; // dodanie sprzetu
	}
	SS_Equipment_In.close();
	
	
	
	
	// 22) Wypisanie informacji o szkole narciarskiej
	
	Debugger << "\nFaza 22\n";
	cout << "\nFaza 22\n";
	
	ofstream SS_OUT1("SS_OUT1.txt");
	SS >> SS_OUT1;
	SS_OUT1.close();
	
	(*A[2]).output();
	
	
	
	
	// 23) Usuniecie nauczycieli ze szkoly narciarskiej
	
	Debugger << "\nFaza 23\n";
	
	ifstream SS_Teachers_Out("SS_Teachers_Out.txt");
	SS_Teachers_Out >> n; // wczytanie do zmiennej n liczby nauczycieli do usuniecia
	for(int i=0; i<n; ++i)
	{
		T << SS_Teachers_Out; // wczytanie nauczyciela
		
		(*A[2]) -= T; // usuniecie nauczyciela
	}
	SS_Teachers_Out.close();
	
	
	
	// 24) Usuniecie uczniow ze szkoly narciarskiej
	
	Debugger << "\nFaza 24\n";
	
	ifstream SS_Students_Out("SS_Students_Out.txt");
	SS_Students_Out >> n; // wczytanie do zmiennej n liczby do usuniecia
	for(int i=0; i<n; ++i)
	{
		S << SS_Students_Out; // wczytanie ucznia
		
		(*A[2]) -= S; // usuniecie ucznia
	}
	SS_Students_Out.close();
	
	
	
	
	// 25) Usuniecie sprzetu ze szkoly narciarskiej
	
	Debugger << "\nFaza 25\n";
	
	ifstream SS_Equipment_Out("SS_Equipment_Out.txt");
	SS_Equipment_Out >> n; // wczytanie do zmiennej n liczby sprzetu do usuniecia
	for(int i=0; i<n; ++i)
	{
		E << SS_Equipment_Out; // wczytanie sprzetu
		
		SS -= E; // dodanie sprzetu
	}
	SS_Equipment_In.close();
	
	
	
	// 26) Wypisanie informacji o szkole narciarskiej
	
	Debugger << "\nFaza 26\n";
	cout << "\nFaza 26\n";
	
	ofstream SS_OUT2("SS_OUT2.txt");
	SS >> SS_OUT2;
	SS_OUT2.close();
	
	(*A[2]).output();
	
	
	
	
	// 27) Kopiowanie szkoly publicznej i zapisanie kopii do pliku wyjsciowego
	
	Debugger << "\nFaza 27\n";
	cout << "\nFaza 27\n";
	
	PublicSchool PuS1 = PuS;
	ofstream PuS1_OUT("PuS1_OUT.txt");
	PuS1.output();
	PuS1 >> PuS1_OUT;
	PuS1_OUT.clear();
	
	
	
	
	// 28) Kopiowanie szkoly prywatnej i zapisanie kopii do pliku wyjsciowego
	
	Debugger << "\nFaza 28\n";
	cout << "\nFaza 28\n";
	
	PrivateSchool PrS1 = PrS;
	ofstream PrS1_OUT("PrS1_OUT.txt");
	PrS.output();
	PrS1 >> PrS1_OUT;
	PrS1_OUT.clear();
	
	
	
	// 29) Kopiowanie szkoly narciarskiej i zapisanie kopii do pliku wyjsciowego
	
	Debugger << "\nFaza 29\n";
	cout << "\nFaza 29\n";
	
	SkiSchool SS1 = SS;
	ofstream SS1_OUT("SS1_OUT.txt");
	SS1.output();
	SS1 >> SS1_OUT;
	SS1_OUT.clear();
	
	
	
	
	// 30) Usuniecie tablicy polimorficznych wskaznikow na szkoly
	
	Debugger << "\nFaza 30\n";
	
	delete [] A;
	
	
	
	
	// 31) Zamykanie Debuggera
	
	Debugger << "\nFaza 31\n";
	
	Debugger.close();
}



int main()
{
	Simulate();
	
	return 0;
}
