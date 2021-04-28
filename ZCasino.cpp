#include <iostream>
#include <string> // Nécessaire pour utiliser des chaînes
#include <cstdlib> // Nécessaire pour utiliser des nombres aléatoires
#include <ctime>
using namespace std;

/*ZCasino un petit jeu de roulette très simplifié dans lequel vous pourrez miser une certaine
somme et gagner ou perdre de l'argent*/

void jeu();
int main()
{
    //Déclaration des variables

    string nom_du_joueur;
    int soldes; // stocke le solde du joueur
    int mise;
    int nombre_mise;
    int numero_gagnant; // stocke le nombre aléatoire
    char choix;
    srand(time(0)); // le générateur aléatoire
    cout << "\n\t\t========BIENVENUE AU ZCASINO=======\n\n";
    cout << "\n\nEntrez votre nom : ";
    getline(cin, nom_du_joueur);
    cout << "\n\nEntrez le montant de votre solde : $";
    cin >> soldes;
    do
    {
        system("cls");
        jeu();
        cout << "\n\nVotre solde actuel est $ " << soldes << "\n";
    // Le solde des paris du joueur
        do
        {
            cout << "Hey, " << nom_du_joueur<<", Entrez le montant de votre mise : $";
            cin >> mise;
            if(mise > soldes)
                cout << "Le solde des paris ne peut pas etre superieur au solde actuel !\n"
                       <<"\nEntrer a nouveau le solde\n ";
        }while(mise > soldes);

        // Le nombre misé et la mise ont été sélectionnés par l'utilisateur, On établit le gain du joueur
        do
        {
            cout << "Entrez le nombre sur lequel vous voulez miser (entre 1 et 10) : ";
            cin >> nombre_mise;
            if(nombre_mise <= 0 || nombre_mise > 10)
                cout << "\nLe nombre doit etre compris entre 1 et 10\n"
                    <<"Entrez a nouveau le numéro: \n ";
        }while(nombre_mise <= 0 || nombre_mise > 10);
        numero_gagnant = rand()%10 + 1;
        if(numero_gagnant == nombre_mise)
        {
            cout << "\n\nFelicitations ! Vous obtenez." << mise * 10<< "$";
            soldes = soldes + mise * 10;
        }
        else
        {
            cout << "Oops, Desole, c'est pas pour cette fois. Vous perdez votre mise. $ "<< mise <<"\n";
            soldes = soldes - mise;
        }
        cout << "\nLe numero gagnant etait : " << numero_gagnant <<"\n";
        cout << "\n"<<nom_du_joueur<<", Votre solde est de " << soldes <<" $"<<"\n";
        if(soldes == 0)
        {
            cout << "Vous n'avez pas assez d'argent pour jouer !";
            break;
        }
        cout << "\n\n-->Voulez-vous rejouer (y/n)? ";
        cin >> choix;
    }while(choix =='Y'|| choix=='y');
    cout << "\n\n\n";
    cout << "\n\nAu revoir. Votre solde est de " << soldes <<" $"<< "\n\n";
    return 0;
}
void jeu()
{
    system("cls");
    cout << "\t\t======REGLES DE DEVIS DES NUMEROS DE CASINO!======\n";
    cout << "\t1. Choisissez un nombre entre 1 et 10\n";
    cout << "\t2. Le gagnant obtient 10 fois la mise d'argent\n";
    cout << "\t3. Mauvais pari, et vous perdez le montant que vous pariez\n\n";
}
