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
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    int a;
    a = TirerNombreMystere();
    cout << a << endl;
    int num = 8;
    TJoueur j;
    InitJoueur(j, "Parrat");
    JouerPartie(j, num);
    return 0;
}

