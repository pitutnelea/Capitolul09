#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Roman.h"
#include "Francez.h"
#include "German.h"
#include "stdlib.h"

using namespace std;

void Meniu()
{
    system ("cls");
    cout<<"Alegeti optiunea dorita:"<<endl;
    cout<<"1. Adaugare participant"<<endl;
    cout<<"2. Afisare sumar"<<endl;
    cout<<"0. Iesire"<<endl;
}

Participant CreazaParticipant()
{
    system ("cls");
    int i = 0;
    cout<<"Alegeti nationalitatea: "<<endl;
    cout<<"1. Roman"<<endl;
    cout<<"2. Francez"<<endl;
    cout<<"3. German"<<endl;
    cout<<"4. Alta"<<endl;
    cin>> i;

    //e ok ce pun in switch?
    switch(i)
    {
        case 1: {Participant *roman = new Roman(); return *roman; } // trebuie scris "return roman"...sm incrcat sa scriu, dar nu imi compileaza
        case 2: {Participant *francez = new Francez(); return *francez;}
        case 3: {Participant *german = new German(); return *german;}
        case 4: {Participant *alta = new Participant();return *alta;}
    }
}

int main()
{
    vector <Participant > *pntParticipanti;
    int nrintrodus;
    cin >> nrintrodus;
    while (nrintrodus !=0)
    {
        Meniu();
        int nr;
        cin >> nr;
        if (nr == 1)
        {
            pntParticipanti->push_back(CreazaParticipant());

        }
        else if (nr == 2)
        {
            system ("cls");
        //2.parcurgeți vectorul pntParticipanti și contorizați câți participanți există din fiecare din cele patru
        //categorii (romani, germani, francezi și alții).
            unsigned int partRomani = 0;
            unsigned int partGermani = 0;
            unsigned int partFrancezi = 0;
            unsigned int partAltii = 0;
            for (Participant elem : *pntParticipanti)
            {
                switch(elem.Vorbeste())
                {
                    case romana: partRomani +=1;break; //este elementul din enum lb germana franceza
                    case germana: partGermani +=1;break;
                    case franceza: partFrancezi +=1;break;
                    default : partAltii +=0; break;
                }
            }
        //3.dacă există cel puțin un participant, indiferent de categorie, afișați linia "Participanti inscrisi pana acum:"
            if ((partRomani>0)&&(partGermani>0)&&(partFrancezi>0)&&(partAltii>0))
            {
                cout<<"Participanti inscrisi pana acum: "<<(partRomani+partGermani+partFrancezi+partAltii) <<endl;
            }
        //4.pentru fiecare din cele patru categorii care au cel puțin un om înscris afișați linia totalCateg Naționalitate.
        //De exemplu dacă sunt 5 români înscriși afișați "5 Romani"
            if (partRomani > 0){cout<< partRomani<< " romani"<<endl;}
            else if (partGermani > 0){cout<<partGermani<< " germani"<<endl;}
            else if (partFrancezi > 0){cout<<partFrancezi<<" francezi"<<endl;}
            else if (partAltii>0){cout<<partAltii<< " altii"<<endl;}
        //5.suspendați execuția până când utilizatorul apasă o tastă. Rezultatul ar trebui să semene cu poza anexată
            cout<<"Press any key to continue"<<endl;
            system("pause");
            int tasta = 0;
            cin >> tasta;
        //în caz că s-a introdus 0 ieșiți din buclă
            if (tasta = 0) {break;}
        }
    }
    //poate că mai trebuie să faceți ceva (sau poate că nu ...)
    //nu mai fac delete pe heap, caci sunt declarate pe heap, dar in zona globala, iar pt zona globala nu se face delete asa-i?
    //goliți vectorul folosind metoda clear()
    pntParticipanti->clear();
    return 0;
}
