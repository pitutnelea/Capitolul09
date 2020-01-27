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

    for (Participant *elem : pntParticipanti)
    {
        delete elem;
    }

    pntParticipanti.clear();
    return 0;
}
