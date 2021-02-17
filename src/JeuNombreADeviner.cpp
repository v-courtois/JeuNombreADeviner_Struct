/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
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
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : nom joueur
// Paramètres de sortie : joueur
// Paramètres d'entrée/sortie :

void InitJoueur(TJoueur &joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nbTentatives = 0;
}

// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : retourne le nombre mystère


int TirerNombreMystere()
{
    srand(time(NULL));
    const int max = 10, min = 1;
    int range = max - min + 1;
    int mystery_number = rand() % range + min;

    return mystery_number;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: nombre a deviner
// Paramètres de sortie:
// Paramètres d'entrée/sortie : le joueur

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
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: nbessais, gagne
// Paramètres de sortie:
// Paramètres d'entrée/sortie : joueur

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
   joueur.nbTentatives = joueur.nbTentatives + nbEssais;
   if (gagne == true) {
        joueur.nbPartiesGagnees++;
   }
   joueur.nbPartiesJouees++;

}


// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: joueur,
// Paramètres de sortie: anbsucces nbechec nbessais.
// Paramètres d'entrée/sortie : aucun

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees - joueur.nbPartiesGagnees;
    nbessais = joueur.nbTentatives;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

