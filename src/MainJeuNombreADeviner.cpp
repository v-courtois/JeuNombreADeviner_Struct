/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    int succes = 0, echec = 0, essais = 0, yesno = 1, nbjoueur = 0;
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "Combien de joueurs vont participer au jeu ?" << endl;
    cin >> nbjoueur;
    string playername;
    TJoueur player[nbjoueur];
    for (int i = 0; i < nbjoueur; i++) {
        cout << endl << "Joueur" << i + 1 << " choisissez votre nom : " << endl;
        cin >> playername;
        InitJoueur(player[i], playername);
    }
    while (yesno != 0) {
        for (int i = 0; i < nbjoueur; i++) {
            int mysteryNumber =  TirerNombreMystere();
            cout << endl << Nom(player[i]) << endl << "Trouvez le nombre mystere : " << endl;
            JouerPartie(player[i], mysteryNumber);
            cout << "-------------------" << endl;
            cout << Nom(player[i]) << endl;
            ResultatsJoueur(player[i], succes, echec, essais);
            cout << "-------------------" << endl;
            cout << "   - Succes : " << succes << endl << "   - Echec : " << echec << endl << "   - Essais : " << essais << endl;
            cout << "-------------------" << endl;
        }
        cout << "Voulez vous rejouer une partie ? O/N (o/n)" << endl;
        cout << "Le nombre de joueur sera conserve et les resultats mis a jours." << endl;
        char answer;
        cin >> answer;
        if (answer == 'n' || answer == 'N') {
            yesno = 0; // si yesno = 0 le jeu s'arrête sinon on rejoue
        }
    }
    return 0;
}

