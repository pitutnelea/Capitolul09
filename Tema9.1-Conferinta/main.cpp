#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Roman.h"
#include "Francez.h"
#include "German.h"

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
    cout<<"Alegeti nationalitatea:"<<endl;
    cout<<"1. Roman"<<endl;
    cout<<"2. Francez"<<endl;
    cout<<"3. German"<<endl;
    cout<<"4. Alta"<<endl;
    cin>> i;

    //Apoi crează pe heap un obiect din clasa corespunzând opțiunii citite.
    //În caz că opțiunea introdusă nu e 1, 2 sau 3 crează pe heap un obiect din clasa Participant.
    //Funcția returnează pointerul către obiectul creat anterior.
    switch(i)
    {
        case 1: {Participant *roman = new Roman(); return *roman; break;}
        case 2: {Participant *francez = new Francez(); return *francez;break;}
        case 3: {Participant *german = new German(); return *german; break;}
        case 4: {Participant *alta = new Participant();return *alta; break;}
    }
}

int main()
{
    //În funcția main definiți vectorul pntParticipanti cu elemente de tip pointer spre Participant.
    vector <Participant> pntParticipanti;
    int nrintrodus;
    cin >> nrintrodus;
    while (nrintrodus !=0)
    {
        Meniu();
        int nr;
        cin >> nr;
        if (nr ==1 )
        {
            pntParticipanti.push_back(CreazaParticipant());
        }
        else if (nr ==2)
        {
            system ("cls");
            //parcurgeți vectorul pntParticipanti și contorizați câți participanți există din fiecare din cele
            //patru categorii (romani, germani, francezi și alții).

            for (Participant elem:pntParticipanti)
            {
                int index_romani;
                switch(elem)
                {
                    case 1: index_romani = elem+1;break;
                }
            }

//dacă există cel puțin un participant, indiferent de categorie, afișați linia "Participanti inscrisi pana acum:"
//pentru fiecare din cele patru categorii care au cel puțin un om înscris afișați linia totalCateg Naționalitate. De exemplu dacă sunt 5 români înscriși afișați "5 Romani"
//suspendați execuția până când utilizatorul apasă o tastă. Rezultatul ar trebui să semene cu poza anexată
        }
    }

    return 0;
}
