/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;
#include "../include/JeuNombreAdeviner.h"
#include <ctime>

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : nom joueur
// Param�tres de sortie : joueur
// Param�tres d'entr�e/sortie :

void InitJoueur(TJoueur &joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nbTentatives = 0;
}

// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : retourne le nombre myst�re


int TirerNombreMystere()
{
    srand(time(NULL));
    const int max = 10, min = 1;
    int range = max - min + 1;
    int mystery_number = rand() % range + min;

    return mystery_number;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: nombre a deviner
// Param�tres de sortie:
// Param�tres d'entr�e/sortie : le joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int var, compteur = 0;
    bool win = false;
    while ((var != nombreADeviner) && (compteur < 4)) {
        cin >> var;
        if (var > nombreADeviner) {
            cout << "Le nombre est inferieur, veuillez retenter" << endl;
            }
        else if (var < nombreADeviner) {
            cout << "Le nombre est superieur, veuillez rententer" << endl;
        }

        compteur = compteur + 1;

    }
    if (var == nombreADeviner) {
            win = true;
            cout << endl << "Bravo ! Vous avez trouve la bonne valeur en : " << compteur << " essai(s)" << endl;
            MajResultatsJoueur(un_joueur, compteur, win);
    }
    else {
            cout << endl << "Mince, vous avez perdu en : " << compteur << " essai(s)" << endl;
            MajResultatsJoueur(un_joueur, compteur, win);
    }


}

// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: nbessais, gagne
// Param�tres de sortie:
// Param�tres d'entr�e/sortie : joueur

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
   joueur.nbTentatives = joueur.nbTentatives + nbEssais;
   if (gagne == true) {
        joueur.nbPartiesGagnees++;
   }
   joueur.nbPartiesJouees++;

}


// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: joueur,
// Param�tres de sortie: anbsucces nbechec nbessais.
// Param�tres d'entr�e/sortie : aucun

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees - joueur.nbPartiesGagnees;
    nbessais = joueur.nbTentatives;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

