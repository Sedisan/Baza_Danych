#include <iostream>
#include <windows.h>
#include <fstream>

#include <sstream>
//#include <stdlib.h>

#define where "Baza_Danych.txt"

struct dane
{
    std::string imie,nazwisko,dodatkowe;
    dane(std::string a=""):imie(a),nazwisko(a),dodatkowe(a)
    {

    }
};

int pozycja_Szukanego();
void enter();
void trunc(const std::string & fname);

std::string informacje();
bool sprawdzacz(unsigned short ala);
void otwieranie_Pliku();
typedef short(*defin)(short);
short zarzadzanie_Decyzja(short a);

short nowa(short a,defin ala);

short strumien_Bledow_I_Konca_Programu(short a);
class Lista_Osob
{
public:
    static std::string SOMETHING;
    static short ilosc_Osob;
    static int tablica[40];
    static short k;


private:
    Lista_Osob() {}
    ~Lista_Osob();
    Lista_Osob(const Lista_Osob&Nie_Oszukasz) {}
    Lista_Osob & operator=(Lista_Osob &To_Tez_Nie_Dziala)
    {
        std::cerr<<"Tego obiektu nie wolno Ci tworzyc! "<<'\n';

        return *this;
    }

};
short Lista_Osob::ilosc_Osob=0;
short Lista_Osob::k=0;
std::string Lista_Osob::SOMETHING = "";

int Lista_Osob::tablica[40]= {};


/*
*WSZYSTKIE PROBLEMY ROZWIAZANE
*
*
*WERSJA v1.00
*
*
*ZA WYJATKIEM:
*PROGRAM DZIALA TYLKO DLA 9 UZYTKOWNIKOW
*
*
*
*
*/
int main();
std::string informacje();
namespace zarzadzanie
{
void zapisywanie_Do_Pliku(const std::string nazwa,std::string &zapisywaczi,std::string &zapisywaczn,std::string &zapisywaczd)
{



std::fstream plik;
plik.open(nazwa+".txt",std::ios::out);


            if(!plik)
            {
                system("cls");

                std::cerr<<"Error! Nie znaleziono danego pliku"<<'\n';
                main();
            }

            plik<<zapisywaczi<<'\n';///Zapisuje od nowa
            plik<<zapisywaczn<<'\n';
            plik<<zapisywaczd<<'\n';
            plik.clear();
            plik.close();




}
}

int main()
{



    while(true)
    {
        std::cout.width(30);
        std::cout<<"MENU GLOWNE: "<<'\n';
        std::cout.width(30);
        std::cout<<"_______________________________ "<<'\n';
        std::cout<<"1. Wprowadz nowa osobe do bazy"<<'\n';
        std::cout.width(30);
        std::cout<<"_______________________________ "<<'\n';
        std::cout<<"2. Edytuj osobe z bazy"<<'\n';
        std::cout.width(30);
        std::cout<<"_______________________________ "<<'\n';
        std::cout<<"3. Usun z bazy osobe"<<'\n';
        std::cout.width(30);
        std::cout<<"_______________________________ "<<'\n';
        std::cout<<"4.Zakoncz "<<'\n';

        short decyzja;
        std::cout<<"Twoja decyzja?(wpisz 1,2,3 lub 4)"<<'\n';
        std::cin>>decyzja;



        decyzja>=0&&decyzja<4?zarzadzanie_Decyzja(decyzja):nowa(decyzja,strumien_Bledow_I_Konca_Programu);

        //system("cls");    get
    }

    // cout << "Hello world!" << endl;
    return 0;
}


short zarzadzanie_Decyzja(short a)
{

    switch(a)
    {
    case 1:
    {
        system("cls");///system to zlo
        printf("%s","\nAktualna lista osob w bazie: ");

        // otwieranie_Pliku();
        unsigned short decyzja;
        std::cout<<"Co chcesz zrobic? "<<'\n'<<"1.Dodac nowa osobe"<<"\n2.Cofnac do menu glownego"<<'\n';
        while(!(std::cin>>decyzja))
        {
            std::cout<<"To nie jest prawidlowa wartosc. Sprobuj ponownie"<<'\n';
            std::cin.clear();
            std::cin.sync();///Kasowanie zbednych znakow

        }
        (decyzja!=1&&decyzja!=2)?zarzadzanie_Decyzja(1):decyzja;
        if(decyzja==2)main();

        dane d1;



        std::cout<<"Wprowadz nazwe pliku do ktorego bedzie zapisana osoba(Nie wprowadzaj cyfr): "<<'\n';
        std::string nazwa;
        std::cin.ignore();
        getline(std::cin,nazwa);
        system("cls");
        bool wprowadzone=0;
        for(unsigned int i=0;i<nazwa.length();i++){
                while(isdigit(nazwa[i]))
                {
                    nazwa.erase(i,1);
                wprowadzone=1;
                }
            //if(isdigit(nazwa[i]))nazwa.erase(i,1);
            }
        wprowadzone?std::cout<<"Twoje cyfry zostaly usuniete. Po usunieciu pozostalo Ci: "<<nazwa<<'\n':std::cout<<"";

        if((nazwa[nazwa.length()-1]=='t') &&(nazwa[nazwa.length()-2]=='x')&&(nazwa[nazwa.length()-3]=='t')&&(nazwa[nazwa.length()-4]=='.'))
        {
            nazwa.erase(nazwa.length()-4,4);
            std::cout<<"Nazwa wynosi: "<<nazwa<<'\n';
        }

        /*
        std::cout<<Lista_Osob::SOMETHING<<'\n';
        Sleep(1000);
        */
        size_t pozycja=Lista_Osob::SOMETHING.find(nazwa);
        bool isset=false;
        if(pozycja!=std::string::npos)
        {


            std::cout<<"Taki plik juz istnieje. Czy chcesz go nadpisac ?(0, nie, 1, tak)"<<'\n';
            isset=true;
            bool decyzja;
            std::cin>>decyzja;
            if((decyzja==0))
                zarzadzanie_Decyzja(1);
            std::cin.ignore();
        }
        Lista_Osob::ilosc_Osob++;


        std::fstream ff;
        ff.open(where,std::ios::out | std::ios::app);
        std::cout<<Lista_Osob::SOMETHING<<'\n';
        // Sleep(5000);

        if(!isset) ff<<Lista_Osob::ilosc_Osob<<"."<<nazwa<<'\n';



        ff.clear();
        ff.close();





        std::fstream plik;


        plik.open(nazwa+".txt",std::ios::out);


        std::cout<<"Podaj imie: "<<"\r\n";
        getline(std::cin,d1.imie)
        std::cout<<"Teraz nazwisko: "<<"\r\n";
        getline(std::cin,d1.nazwisko);
        std::cout<<"Wprowadz informacje charakteryzujace ta osobe: "<<"\r\n";
        getline(std::cin,d1.dodatkowe);

        plik<<d1.imie<<'\n';
        plik<<d1.nazwisko<<'\n';
        plik<<d1.dodatkowe<<'\n';


        plik.clear();
        plik.close();
        system("cls");
        std::cout<<"Osoba :"<<d1.imie<<" "<<d1.nazwisko<<'\n'<<"zostala wprowadzona do bazy";
        Sleep(1000);
        std::cout<<'\n';
        enter();
        break;
    }
    case 2:
    {

        std::cout<<"Co chcesz zrobic ? "<<'\n';
        std::cout.width(30);
        std::cout<<"_______________________________ "<<'\n';
        std::cout<<"1.Przegladac osobe "<<'\n';
        std::cout.width(30);
        std::cout<<"_______________________________ "<<'\n';
        std::cout<<"2.Edytowac osobe "<<'\n';
        std::cout.width(30);
        std::cout<<"_______________________________ "<<'\n';
        std::cout<<"3.Powrot do menu "<<'\n';

        while(!(std::cin>>a))
        {
            std::cout<<"To nie jest prawidlowa wartosc. Sprobuj ponownie"<<'\n';
            std::cin.clear();
            std::cin.sync();///Czysci ze zbednych znakow

        }

        switch (a)
        {
        case 1:
        {
           
            otwieranie_Pliku();
            
            Sleep(1000);

            /*
            std::cout<<"O ktorej osobie chcialbys uzyskac informacje: "<<'\n';
            while(!(std::cin>>decyzja))
            {
                std::cin.clear();
                std::cin.sync();
            }
            decyzja<1||decyzja>Lista_Osob::k?zarzadzanie_Decyzja(2):decyzja;
            */



            std::string sklejacz=informacje();

            std::fstream otwarcie;
            otwarcie.open(sklejacz+".txt",std::ios::in);
            if(!otwarcie)
            {
                system("cls");

                std::cerr<<"Error! Nie znaleziono danego pliku"<<'\n';
                main();
            }
            std::string gdzie;
            int n=1;
            system("cls");

            while(getline(otwarcie,gdzie))
            {
                std::cout.width(30);
                switch(n)
                {
                case 1:
                {
                    std::cout<<"Imie: "<<gdzie<<'\n';

                    break;
                }
                case 2:
                {
                    std::cout<<"Nazwisko: "<<gdzie<<'\n';

                    break;
                }
                case 3:
                {
                    std::cout<<"Informacje dodatkowe: "<<gdzie<<'\n';

                    break;
                }

                }
                n++;
            }




            otwarcie.clear();
            otwarcie.close();

            std::cin.ignore();
            enter();

            break;
        }
        case 2:
        {
            std::string sklejacz;
            otwieranie_Pliku();
            sklejacz=informacje();

            std::fstream otwieracz;



            otwieracz.open(sklejacz+".txt",std::ios::in);

            if(otwieracz.is_open()==false)
            {
                system("cls");

                std::cerr<<"Error! Nie znaleziono danego pliku"<<'\n';
                main();
            }
            std::string line;
            int nr_Linii=1;

            std::string zapisywaczi="",zapisywaczn="",zapisywaczd="";



            while(getline(otwieracz,line))
            {
                switch(nr_Linii)
                {
                default:

                {
                    
                    if(nr_Linii==1)
                        zapisywaczi+=line;
                    if(nr_Linii==2)
                        zapisywaczn+=line;
                    if(nr_Linii==3)
                        zapisywaczd+=line;
                    break;
                }
                }
                nr_Linii++;
            }
            int nowy;
            std::istringstream temp(sklejacz);
            temp>>nowy;

            otwieracz.clear();
            otwieracz.close();
            std::cout<<"Co chcialbys edytowac ?(\nWpisz 0, by wybrac informacje dodatkowe,\n1 -> imie,\n2 -> imie i nazwisko,\n3->imie i informacje dodatkowe,\n4->nazwisko i informacje dodatkowe,\n5->wszystkie,\n6->cofnij) "<<'\n';
            while(!(std::cin>>nowy))
            {
                std::cout<<"To nie jest prawidlowa wartosc. Sprobuj ponownie"<<'\n';
                std::cin.clear();
                std::cin.sync();

            }
            nowy>5||nowy<0?zarzadzanie_Decyzja(2):nowy;

            std::fstream( sklejacz+".txt", std::ios::trunc | std::ios::out ).flush();
            zarzadzanie::zapisywanie_Do_Pliku(sklejacz,zapisywaczi,zapisywaczn,zapisywaczd);
            Sleep(1000);
            switch(nowy)
            {
            case 0:
            {
                getline(std::cin,zapisywaczi);
                std::cout<<"Wprowadz informacje dodatkowe: "<<'\n';
                getline(std::cin,zapisywaczd);
                zarzadzanie::zapisywanie_Do_Pliku(sklejacz,zapisywaczi,zapisywaczn,zapisywaczd);

                break;
            }
            case 1:
            {


                getline(std::cin,zapisywaczi);
                std::cout<<"Wprowadz imie: "<<'\n';
                getline(std::cin,zapisywaczi);

                zarzadzanie::zapisywanie_Do_Pliku(sklejacz,zapisywaczi,zapisywaczn,zapisywaczd);

                break;
            }
            case 2:
            {


                getline(std::cin,zapisywaczi);
                std::cout<<"Wprowadz imie: "<<'\n';
                getline(std::cin,zapisywaczi);
                std::cout<<"Wprowadz nazwisko: "<<'\n';
                getline(std::cin,zapisywaczn);
                zarzadzanie::zapisywanie_Do_Pliku(sklejacz,zapisywaczi,zapisywaczn,zapisywaczd);

                break;
            }
            case 3:
            {


                getline(std::cin,zapisywaczi);
                std::cout<<"Wprowadz imie: "<<'\n';
                getline(std::cin,zapisywaczi);

                std::cout<<"Wprowadz informacje dodatkowe: "<<'\n';
                getline(std::cin,zapisywaczd);
               zarzadzanie::zapisywanie_Do_Pliku(sklejacz,zapisywaczi,zapisywaczn,zapisywaczd);

                break;
            }
            case 4:
            {


                getline(std::cin,zapisywaczi);
                std::cout<<"Wprowadz nazwisko: "<<'\n';
                getline(std::cin,zapisywaczn);

                std::cout<<"Wprowadz informacje dodatkowe: "<<'\n';
                getline(std::cin,zapisywaczd);
                zarzadzanie::zapisywanie_Do_Pliku(sklejacz,zapisywaczi,zapisywaczn,zapisywaczd);

                break;
            }
            case 5:
            {


                getline(std::cin,zapisywaczi);
                std::cout<<"Wprowadz imie: "<<'\n';
                getline(std::cin,zapisywaczi);
                std::cout<<"Wprowadz nazwisko: "<<'\n';
                getline(std::cin,zapisywaczn);

                std::cout<<"Wprowadz informacje dodatkowe: "<<'\n';
                getline(std::cin,zapisywaczd);
               zarzadzanie::zapisywanie_Do_Pliku(sklejacz,zapisywaczi,zapisywaczn,zapisywaczd);

                break;
            }
            case 6:
            {
                zarzadzanie_Decyzja(2);
                break;
            }
            default:
            {
                main();
                break;
            }



            }



            enter();

            break;
        }
        default:
        {
            main();

            break;
        }
        }




        break;
    }
    case 3:
    {

        otwieranie_Pliku();

        size_t pozycja=pozycja_Szukanego();

        int k=0;
        unsigned int i=0;
        int ktora=0;
        std::string sklejacz="";
        for(i=pozycja+2; i<Lista_Osob::SOMETHING.length(); i++)
        {
            k++;

            if(isdigit(Lista_Osob::SOMETHING[i]))
            {
                ktora=static_cast <int>(Lista_Osob::SOMETHING[i]);
                break;
            }
            sklejacz+=Lista_Osob::SOMETHING[i];
        }

        sklejacz=sklejacz+".txt";
     
        Lista_Osob::SOMETHING.erase(i-k-1,k+1);
      

        if(ktora==0)Lista_Osob::SOMETHING.erase(i-k-2,k+1);///Jesli k wskazuje na ostatni element
        //std::cout<<"Po calej iteracji wynosi: "<<Lista_Osob::SOMETHING<<'\n';
 


        if(!(remove(sklejacz.c_str())))
        {
            std::fstream(where,std::ios::trunc | std::ios::out).flush();

            std::fstream wyczyszczony;

            wyczyszczony.open(where,std::ios::out);

            wyczyszczony<<Lista_Osob::SOMETHING<<'\n';


            wyczyszczony.clear();
            wyczyszczony.close();
            otwieranie_Pliku();
            std::cout<<'\n';
            std::cout.width(30);
            std::cout<<"Udalo sie usunac dane z : "<<sklejacz<<'\n';
            Sleep(1000);
            std::cin.ignore();
            enter();

        }
        else
        {
            std::cout<<"Nie udalo sie usunac z bazy: "<<sklejacz<<" .Sprobuj ponownie...";
            zarzadzanie_Decyzja(3);
        }


    }
    default:
        main();
        break;
    }


    return a;
}
inline short nowa(short a,defin ala)
{
    a!=4?std::cout<<"To nie jest poprawna wartosc"<<'\n':
                  std::cout<<"Dziekujemy za skorzystanie z Naszego programu"<<'\n';
    return ala(a);
}
inline short strumien_Bledow_I_Konca_Programu(short a)
{
    std::cin.ignore();
    atexit(enter);
    a==4?exit(0):exit(1);
    return EXIT_FAILURE;
}
void otwieranie_Pliku()
{
    Lista_Osob::SOMETHING="";
    std::fstream otwieranie;
    otwieranie.open(where,std::ios::in);
#undef where

    std::ostringstream temp;
    temp<<Lista_Osob::ilosc_Osob;
    std::string line;
    int nr_Linii=1;

    while(getline(otwieranie,line))
    {
        switch(nr_Linii)
        {
        default:
        {
            Lista_Osob::SOMETHING+=line;
            break;
        }
        }
        nr_Linii++;
    }
    system("cls");
    if(Lista_Osob::SOMETHING=="")
    {
        std::cout<<"Baza jest pusta..."<<'\n';
        Sleep(1000);
        main();
    }


    Lista_Osob::k=0;
    for(unsigned short i=0; i<Lista_Osob::SOMETHING.length(); i++)
    {
        if(isdigit(Lista_Osob::SOMETHING[i]))
        {
            Lista_Osob::k+=1;
            printf("%c",'\n');

            Lista_Osob::tablica[Lista_Osob::k]=Lista_Osob::k;

            std::string s;
            std::stringstream out;
            out << Lista_Osob::k;
            s = out.str();
            for(unsigned short j=0; j<s.length(); j++)
                Lista_Osob::SOMETHING[i]=s[j];///Rozwiazanie super tymczasowe()Gdy jest wiecej niz 10 osob nie dziala


        }

        printf("%c",Lista_Osob::SOMETHING[i]);
    }
    printf("\n%s","Aktualnie w bazie mamy: ");
    printf("%d",Lista_Osob::k);
    printf("%s\n"," uzytkownikow");

    
    otwieranie.clear();
    otwieranie.close();
}
bool sprawdzacz(unsigned short ala)
{
    return ala>Lista_Osob::k || ala<1?false:true;
}
std::string informacje()
{
    size_t pozycja=pozycja_Szukanego();
    std::string sklejacz="";
    for(unsigned int i=pozycja+2; i<Lista_Osob::SOMETHING.length(); i++)
    {
        if(isdigit(Lista_Osob::SOMETHING[i]))break;
        sklejacz+=Lista_Osob::SOMETHING[i];
    }

    std::cout<<sklejacz<<'\n';
    return sklejacz;
}
void trunc( const std::string & fname )
{
    std::fstream( fname+".txt", std::ios::trunc | std::ios::out ).flush();
}
int pozycja_Szukanego()
{
    std::string ktora;
    std::cout<<"O ktora osobe Ci chodzi ? "<<'\n';

    std::cin>>ktora;


    std::istringstream temp(ktora);
    int nowy;
    std::istringstream (ktora)>> nowy;
    sprawdzacz(nowy)==false?std::cout<<"Blad! Twoja wartosc jest nieprawidlowa. Sprobuj ponownie"<<'\n'&&main():nowy;




    size_t pozycja=Lista_Osob::SOMETHING.find(ktora);
    std::cout<<"Pozycja: "<<pozycja<<'\n';
    Sleep(1000);
    if(pozycja!=std::string::npos)
    {
        system("cls");
  
    }
    else
    {
        std::cout<<"Nie znaleziono"<<'\n';
        pozycja_Szukanego();
    }

    return pozycja;

}
void enter()
{
    std::cout<<"Wcisnij enter, by kontynuowac..."<<'\n';
    std::cin.get();

}
