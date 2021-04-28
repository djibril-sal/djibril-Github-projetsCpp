#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string melangerLettres(string mot)
{
    string melange;
    int position(0);

    // Tant que nous n'avons pas extrait toutes les lettres du mot
    while (mot.size() != 0)
    {
        // On choisit un numéro de lettre au hasard dans le mot
        position = rand() % mot.size();
        // On ajoute la lettre dans le mot mélangé
        melange += mot[position];
        // On retire cette lettre du mot mystère pour ne pas la prendre une 2e fois
        mot.erase(position, 1);
    }

    // On renvoie le mot mélangé
    return melange;
}

int main()
{
    string motMystere, motMelange, motUtilisateur;

    // Initialisation des nombres aléatoires
    srand(time(0));


    // 1 : On demande à saisir un mot
    cout << "Saisissez un mot" << endl;
    cin >> motMystere;

    // 2 : On récupère le mot avec les lettre mélangées dans motMelange
    motMelange = melangerLettres(motMystere);

    // 3 : On demande à l'utilisateur quel est le mot mystère
    do
    {
        cout << endl << "Quel est ce mot ? " << motMelange << endl;
        cin >> motUtilisateur;

        if (motUtilisateur == motMystere)
        {
            cout << "Bravo !" << endl;
        }
        else
        {
            cout << "Ce n'est pas le mot !" << endl;
        }
    }while (motUtilisateur != motMystere); // On recommence tant qu'il n'a pas trouvé

    return 0;
}
