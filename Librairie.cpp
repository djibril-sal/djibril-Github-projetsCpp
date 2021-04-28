#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class livre	{
private:
    //Création des attributs
	char *auteur,*titre,*editeur;
	float *prix;
	int *stock;
public:
	livre()	{
	auteur= new char[20];
	titre=new char[20];
	editeur=new char[20];
	prix= new float;
	stock=new int;
	}
	//Création des méthodes
	void ajouter();
	void modifier();
	void afficher();
	int search(char[],char[]);
	void acheter_un_livre();

};

void livre::ajouter()	{
	cin.ignore();
	cout<<"\nEntrez le nom de l'auteur : ";    cin.getline(auteur,20);
	cout<<"Entrez le nom du titre : ";         cin.getline(titre,20);
	cout<<"Entrez le nom de l'editeur : ";     cin.getline(editeur,20);
	cout<<"Entrez le prix en Euro : ";         cin>>*prix;
	cout<<"Entrer le rayon du stock : ";       cin>>*stock;

}

void livre::modifier()	{

	cout<<"\nEntrez le nom de l'auteur : ";    cin.getline(auteur,20);
	cout<<"Entrez le nom du titre : ";         cin.getline(titre,20);
	cout<<"Entrez le nom de l'editeur : ";     cin.getline(editeur,20);
	cout<<"Entrez le prix en Euro : ";         cin>>*prix;
	cout<<"Entrer le rayon du stock : ";       cin>>*stock;

}

void livre::afficher()	{
	cout<<"\nEntrez le nom de l'auteur : "<<auteur;
	cout<<"\nEntrez le nom du titre : "<<titre;
	cout<<"\nEntrez le nom de l'editeur : "<<editeur;
	cout<<"\nEntrez le prix : "<<*prix<<" €";
	cout<<"\nEntrer le rayon du stock : "<<*stock;

}

int livre::search(char achatA[20],char achatB[20] )	{
	if(strcmp(achatA,titre)==0 && strcmp(achatB,auteur)==0)
		return 1;
	else return 0;

}

void livre::acheter_un_livre()	{
	int compte;
	cout<<"\nEntrez le nombre de livres a acheter : ";
	cin>>compte;
	if(compte<=*stock)	{
		*stock=*stock-compte;
		cout<<"\nLivres achetes avec succes";
		cout<<"\nMontant: "<<(*prix)*compte<<" €";
	}
	else
		cout<<"\nLivre non en stock";
}

int main()	{
	livre *B[20];
	int i=0,r,t,choix;
	char titreAchat[20],auteurAchat[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Ajouter un nouveau livre"
		<<"\n2. Acheter un livre"
		<<"\n3. Rechercher un livre"
		<<"\n4. Modifier un livre"
		<<"\n5. Sortir"
		<<"\n\nEntrez votre choix: ";
		cin>>choix;

		switch(choix)	{
			case 1:	B[i] = new livre;
				B[i]->ajouter();
				i++;	break;

			case 2: cin.ignore();
				cout<<"\nEntrez le titre du livre : "; cin.getline(titreAchat,20);
				cout<<"Entrez l'auteur du livre : ";  cin.getline(auteurAchat,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(titreAchat,auteurAchat))	{
						B[t]->acheter_un_livre();
						break;
					}
				}
				if(t==1)
				cout<<"\nCe livre n'est pas en stock";

				break;
			case 3: cin.ignore();
				cout<<"\nEntrez le titre du livre : "; cin.getline(titreAchat,20);
				cout<<"Entrez l'auteur du livre : ";  cin.getline(auteurAchat,20);

				for(t=0;t<i;t++)	{
					if(B[t]->search(titreAchat,auteurAchat))	{
						cout<<"\nLivre trouve avec succes";
						B[t]->afficher();
						break;
					}
				}
				if(t==i)
				cout<<"\nCe livre n'est pas en stock";
				break;

			case 4: cin.ignore();
				cout<<"\nEntrez le titre du livre : "; cin.getline(titreAchat,20);
				cout<<"Entrez l'auteur du livre : ";  cin.getline(auteurAchat,20);

				for(t=0;t<i;t++)	{
					if(B[t]->search(titreAchat,auteurAchat))	{
						cout<<"\nLivre trouvé avec succes";
						B[t]->modifier();
						break;
					}
				}
				if(t==i)
				cout<<"\nCe livre n'est pas en stock";
				break;

			case 5: exit(0);
			default: cout<<"\nChoix saisi invalide";

		}
	}




	return 0;
}
