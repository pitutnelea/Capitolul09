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

Participant *CreazaParticipant()
{
    system ("cls");
    cout<<"Alegeti nationalitatea: "<<endl;
    cout<<"1. Roman"<<endl;
    cout<<"2. Francez"<<endl;
    cout<<"3. German"<<endl;
    cout<<"4. Alta"<<endl;
    int i = 0;
    cin>> i;
    switch(i)
    {
        case 1: {Participant *roman = new Roman(); return roman;break;}
        case 2: {Participant *francez = new Francez(); return francez;break;}
        case 3: {Participant *german = new German(); return german;break;}
        case 4: {Participant *alta = new Participant();return alta;break;}
    }
    return 0;
}

int main()
{
    vector <Participant *> pntParticipanti;
    int nrintrodus = 1;
    while (nrintrodus !=0)
    {
        Meniu();
        cin >> nrintrodus;
        if (nrintrodus == 1)
        {
            pntParticipanti.push_back(CreazaParticipant());
        }
        else if (nrintrodus == 2)
        {
            system ("cls");
            unsigned int partRomani = 0;
            unsigned int partGermani = 0;
            unsigned int partFrancezi = 0;
            unsigned int partAltii = 0;
            for (Participant *elem : pntParticipanti)
            {
                switch(elem->Vorbeste())
                {
                    case romana: partRomani +=1;break;
                    case germana: partGermani +=1;break;
                    case franceza: partFrancezi +=1;break;
                    default: partAltii +=1; break;
                }
            }

            if ((partRomani>0)||(partGermani>0)||(partFrancezi>0)||(partAltii>0))
            {
                cout<<"Participanti inscrisi pana acum: "<<(partRomani+partGermani+partFrancezi+partAltii) <<endl;
                if (partRomani > 0){cout<< partRomani<< " romani"<<endl;}
                if (partGermani > 0){cout<<partFrancezi<< " francezi"<<endl;}
                if (partFrancezi > 0){cout<<partGermani<<" germani"<<endl;}
                if (partAltii > 0){cout<<partAltii<< " altii"<<endl;}
            }
            system("pause");
        }
    }

    //trebuie sa sterg obiectele create pe heap
    for (Participant *elem : pntParticipanti)
    {
        delete elem;
    }

    pntParticipanti.clear();
    return 0;
}

/*Veți modela o conferință din punct de vedere al participanților. În acest scop veți defini următoarele entități:

Enum-ul cu scope Limba cu elementele engleza, romana, germana și franceza.
Clasa Participant:
    metodă publică: Vorbeste, care nu primește nimic și returnează o valoare de tip Limba. Metoda va returna Limba::engleza

Clasa Roman care moștenește clasa Participant:
    metodă publică: reimplementează (override) metoda Vorbeste. Metoda va returna Limba::romana

Clasa Francez care moștenește clasa Participant:
    metodă publică: reimplementează (override) metoda Vorbeste. Metoda va returna Limba::franceza

Clasa German care moștenește clasa Participant:
    metodă publică: reimplementează (override) metoda Vorbeste. Metoda va returna Limba::germana

În main.cpp definiți funcția Meniu care nu primește nimic și nu returnează nimic. Ea șterge ecranul și afișează meniul următor:
    Alegeti optiunea dorita:
    1. Adaugare participant
    2. Afisare sumar
    0. Iesire

În main.cpp definiți funcția CreazaParticipant care nu primește nimic și returnează un pointer spre Participant.
Funcția șterge ecranul și afișează meniul
    Alegeti nationalitatea:
    1. Roman
    2. Francez
    3. German
    4. Alta
și citește de la tastatură opțiunea utilizatorului. Apoi crează pe heap un obiect din clasa corespunzând opțiunii citite.
În caz că opțiunea introdusă nu e 1, 2 sau 3 crează pe heap un obiect din clasa Participant.
Funcția returnează pointerul către obiectul creat anterior.

În funcția main definiți vectorul pntParticipanti cu elemente de tip pointer spre Participant.

Apoi definiți o buclă în care să rămâneți câtă vreme nu se introduce 0. În buclă:
    apelați funcția Meniu
    citiți acțiunea dorită de la tastatură
        în caz că s-a introdus 1 apelați funcția CreazaParticipant și introduceți pointerul pe care îl returnează ea în pntParticipanti.
        în caz că s-a introdus 2
            ștergeți ecranul
            parcurgeți vectorul pntParticipanti și contorizați câți participanți există din fiecare din cele patru categorii (romani, germani, francezi și alții).
            dacă există cel puțin un participant, indiferent de categorie, afișați linia "Participanti inscrisi pana acum:"
            pentru fiecare din cele patru categorii care au cel puțin un om înscris afișați linia totalCateg Naționalitate. De exemplu dacă sunt 5 români înscriși afișați "5 Romani"
            suspendați execuția până când utilizatorul apasă o tastă. Rezultatul ar trebui să semene cu poza anexată

în caz că s-a introdus 0 ieșiți din buclă
poate că mai trebuie să faceți ceva (sau poate că nu ...)
goliți vectorul folosind metoda clear()
Nota 1: un mod de a goli ecranul e apelând funcția system("CLS"); (header stdlib.h)
Nota 2: un mod de a pauza execuția e apelând funcția system("pause");*/
