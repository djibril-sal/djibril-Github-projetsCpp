#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>


using namespace std;

static int p = 0;

class a

{

  char busn[5], conducteur[10], arrivee[5], depart[5], De[10], A[10], siege[8][4][10];

public:

  void inscrire();

  void reserver();

  void vide();

  void afficher();

  void disponible();

  void position(int i);

}

bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void a::inscrire()

{

  cout<<"Entrez le numero du bus : ";

  cin>>bus[p].busn;

  cout<<"\nEntrez le nom du conducteur : ";

  cin>>bus[p].conducteur;

  cout<<"\nHeure de depart : ";

  cin>>bus[p].depart;

  cout<<"\nHeure d'arrivee : ";

  cin>>bus[p].arrivee;

  cout<<"\nVille de depart : \t\t\t";

  cin>>bus[p].De;

  cout<<"\nVille d'arrivee : \t\t\t";

  cin>>bus[p].A;

  bus[p].vide();

  p++;

}

void a::reserver()

{

  int siege;

  char nombre[5];

  top:

  cout<<"Numero du Bus : ";

  cin>>nombre;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, nombre)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nNombre de siege : ";

    cin>>siege;

    if(siege>32)

    {

      cout<<"\nIl n'y a que 32 places disponibles dans ce bus.";

    }

    else

    {

    if (strcmp(bus[n].siege[siege/4][(siege%4)-1], "Vide")==0)

      {

        cout<<"Entrez le nom du passager : ";

        cin>>bus[n].siege[siege/4][(siege%4)-1];

        break;

      }

    else

      cout<<"Le numero siege est deja reserve.\n";

      }

      }

    if(n>p)

    {

      cout<<"Entrez le numero de bus correct.\n";

      goto top;

    }

  }


void a::vide()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].siege[i][j], "Vide");

    }

  }

}

void a::afficher()

{

  int n;

  char nombre[5];

  cout<<"Entrez le numero bus : ";

  cin>>nombre;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, nombre)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Numero Bus : \t"<<bus[n].busn

  <<"\nConducteur : \t"<<bus[n].conducteur<<"\t\tHeure d'arrivee : \t"

  <<bus[n].arrivee<<"\tHeure de depart :"<<bus[n].depart

  <<"\nDe : \t\t"<<bus[n].De<<"\t\tA  \t\t"<<

  bus[n].A<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].siege[i][j],"Vide")!=0)

      cout<<"\nNumero du siege "<<(a-1)<<" est reserve pour "<<bus[n].siege[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Entrez le numéro de bus correct : ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].siege[i][j], "Vide")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].siege[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].siege[i][j];

        }

      }

    }

  cout<<"\n\nIl y a "<<p<<" des sièges vides dans le bus : "<<bus[l].busn;

  }

void a::disponible()

{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"Nuumero du Bus : \t"<<bus[n].busn<<"\nConducteur : \t"<<bus[n].conducteur

    <<"\t\tHeure d'arrivee : \t"<<bus[n].arrivee<<"\tHeure de depart : \t"

    <<bus[n].depart<<"\nDe : \t\t"<<bus[n].De<<"\t\tA : \t\t\t"

    <<bus[n].A<<"\n";

    vline('*');

    vline('_');

  }

}

int main()

{

system("cls");

int w;

while(1)

{

    //system("cls");

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.Inscription\n\t\t\t"

  <<"2.Reservation\n\t\t\t"

  <<"3.afficher\n\t\t\t"

  <<"4.Buses disponibles. \n\t\t\t"

  <<"5.Sortir";

  cout<<"\n\t\t\tEntrez votre choix :-> ";

  cin>>w;

  switch(w)

  {

    case 1:  bus[p].inscrire();

      break;

    case 2:  bus[p].reserver();

      break;

    case 3:  bus[0].afficher();

      break;

    case 4:  bus[0].disponible();

      break;

    case 5:  exit(0);

  }

}

return 0;

}
