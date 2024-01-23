#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <functional>

#include "Client.h"
#include "Fournisseur.h"
#include "Panier.h"
#include "Produit.h"
#include "Constants.h"

using namespace std;
namespace testing {
    string redirect_stdout(function<void()> func) {
        stringstream buffer;
        auto old_cout = cout.rdbuf();

        cout.rdbuf(buffer.rdbuf());
        func();

        cout.rdbuf(old_cout);

        return buffer.str();
    }
}
  void  supprimerR (string &  sortie)
  {
    string apres="";
   
    for ( int i = 0 ; i < sortie.size(); i++)
      if (sortie[i] != '\r')
         apres = apres + sortie[i];
     sortie = apres;     
  }
// Test pour Produit (3 points)
double testProduit() {
    double points = 0.0;

    Produit Produit1;
    Produit Produit2(NOM_1, CATEGORIE_1, PRIX_1);

    // Test du constructeur par defaut
    if (Produit1.getNom() == "outil" && Produit1. getCategorie() == 0 && Produit1.getPrix() == 0) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Le constructeur par defaut ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test du constructeur par parametres
    if (Produit2.getNom() == NOM_1 && Produit2.getCategorie() == CATEGORIE_1 && Produit2.getPrix() == PRIX_1) {
        points += 1;
    }
    else {
        cout << "\033[31m" << "Le constructeur par parametres ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test des setters et getters
    Produit1.setNom(NOM_2);
    Produit1.setCategorie(CATEGORIE_2);
    Produit1.setPrix(PRIX_2);
    if (Produit1.getNom() == NOM_2 && Produit1.getCategorie() == CATEGORIE_2 && Produit1.getPrix() == PRIX_2) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Les setters et getters ne fonctionnent pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la methode afficher
    Produit Produit3(NOM_1, CATEGORIE_1, PRIX_1);
    
    string sortie = testing::redirect_stdout([&] { Produit3.afficher(); });
   
    string sortieAttendue = "\t"+ NOM_1 +  "\n\tCategorie:\t" + 
                            to_string(CATEGORIE_1) + "\n\tPrix:\t\t$" + 
                            to_string(PRIX_1)+ "\n";

    if (sortie == sortieAttendue) {
        points += 1;
    }
    else {
        cout << "\033[31m" << "La methode afficher ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }
    return points;
}

// Test pour Client (4 points)
double testClient() {
    double points = 0.0;

    Client Client1;
    Client Client2(CLIENT_1, PRENOM_1, IDENTIFIANT_1, CODEPOSTAL_1);

    // Test du constructeur par defaut
    if (Client1.getNom() == "" && Client1.getPrenom() == "" && 
         Client1.getIdentifiant() == 0 && Client1.getCodePostal()=="" ){
           points += 0.5;
    }
    else {
        cout << "\033[31m" << "Le constructeur par defaut ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test du constructeur par parametres
    if (Client2.getNom() == CLIENT_1 && Client2.getPrenom() == PRENOM_1 && 
         Client2.getIdentifiant() == IDENTIFIANT_1  && Client2.getCodePostal() == CODEPOSTAL_1) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Le constructeur par parametres ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test des setters et getters
    Client1.setNom(CLIENT_2);
    Client1.setPrenom(PRENOM_2);
    Client1.setIdentifiant(IDENTIFIANT_2);
    Client1.setCodePostal(CODEPOSTAL_2);
    if (Client1.getNom() == CLIENT_2 && Client1.getPrenom() == PRENOM_2 && 
        Client1.getIdentifiant() == IDENTIFIANT_2  && Client1.getCodePostal() == CODEPOSTAL_2) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Les setters et getters ne fonctionnent pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la methode afficher
    Client Client3(CLIENT_1, PRENOM_1, IDENTIFIANT_1, CODEPOSTAL_1);
    string sortie = testing::redirect_stdout([&] { Client3.afficher(); });
    string sortieAttendue = CLIENT_1 + ": " + PRENOM_1 + " - Identifiant: " + to_string(IDENTIFIANT_1) +  " le panier est vide "+"\n";
    if (sortie == sortieAttendue) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "La methode afficher ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }
    // Test  de la  méthode acheterProduit
    Produit *  Produit2 = new Produit(NOM_1, CATEGORIE_1, PRIX_1);
    Client2.acheterProduit(Produit2);
    if (Client2.getPanier()->getContenuPanier().size() == 1)
       points += 1;
    else {
        cout << "\033[31m" << "La méthode acheterProduit n'est pas correct." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    // Test de la méthode supprimerProduit
    Produit *  Produit3 = new Produit(NOM_3, CATEGORIE_3, PRIX_3);
    Client2.acheterProduit(Produit3);
    Client2.supprimerProduit(Produit3);
    if (Client2.getPanier()->getContenuPanier().size() == 1)
       points += 0.5;
    else {
        cout << "\033[31m" << "La méthode supprimerProduit n'est pas correct." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

// Test  de la  méthode livrerPanier
    Client2.livrerPanier();
    if (Client2.getPanier()  == nullptr)
       points += 0.5;
    else {
        cout << "\033[31m" << "La méthode livrerPanier n'est pas correct." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test pour Panier (6 points)
double testPanier() {
    double points = 0.0;

    Panier panier1;
    // Test du constructeur par defaut
    if (panier1.getTotalAPayer() == 0  && panier1.getNombreContenuPanier() == 0 )
    { points += 0.5;

    }
    else {
        cout << "\033[31m" << "Le constructeur par defaut de Panier ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
  
    // Creer des Produits
    vector<Produit*> Produits = {
        new Produit(NOM_1, CATEGORIE_1, PRIX_1),
        new Produit(NOM_3, CATEGORIE_3, PRIX_3),
        new Produit(NOM_4, CATEGORIE_4, PRIX_4),
    };

    // Ajouter les Produits dans le panier
     panier1.ajouterProduit(Produits[0]);
     panier1.ajouterProduit(Produits[1]);

    // Test getContenuPanier()
    if (panier1.getNombreContenuPanier() == 2) {
       points += 1;
    }
    else
     {
        cout << "\033[31m" << "La méthode ajouterProduit ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
     // Test  getTotalAPayer()

    if (panier1.getTotalAPayer() == 60) {
       points += 0.5;
    }
    else
     {
        cout << "\033[31m" << "La méthode getTotalAPayer ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    // test   ajouter memeProduit
    panier1.ajouterProduit(Produits[1]);
    if (panier1.getNombreContenuPanier() == 2) {
       points += 1;
    }
    else
     {
        cout << "\033[31m" << "La méthode ajouterProduit ne vérifie pas l'ajout d'un meme produit." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
   // test   chercherProduit
     
    if (panier1.chercherProduit(Produits[1])) {
       points += 0.5;
    }
    else
     {
        cout << "\033[31m" << "La méthode chercherProduit ne vérifie pas l'ajout d'un meme produit." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    // test supprimerProduit
    panier1.ajouterProduit(Produits[2]);
     panier1.supprimerProduit(Produits[2]);
     if (panier1.getNombreContenuPanier() == 2) {
       points += 0.5;
    }
    else
     {
        cout << "\033[31m" << "La méthode supprimerProduit ne fonctionne pas." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // test   livrerPanier
     panier1.livrerPanier();
    if (panier1.getNombreContenuPanier() == 0 && panier1.getTotalAPayer()== 0) {
       points += 1;
    }
    else
     {
        cout << "\033[31m" << "La méthode livrerPanier  ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    //  test afficher
    string sortie = testing::redirect_stdout([&] { panier1.afficher(); });
    string sortieAttendue = "le panier \ntotalPanier " + to_string (panier1.getTotalAPayer())+"\n";
    
    
    if (sortie == sortieAttendue) {
        points += 1;
    }
    else {
        cout << "\033[31m" << "La methode afficher ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }
        
    return points;
}

// Test Fournisseur (points: 7)
double testFournisseur() {
    double points = 0.0;

    Fournisseur  fournisseur(FOURNISSEUR_1);

    // Cr�er des Produits
     vector<Produit*> Produits = {
        new Produit(NOM_1, CATEGORIE_1, PRIX_1),
        new Produit(NOM_3, CATEGORIE_3, PRIX_3),
        new Produit(NOM_4, CATEGORIE_4, PRIX_4),
        new Produit(NOM_5, CATEGORIE_5, PRIX_5),
    };
    
    // Ajouter des Produits et des Clients
    fournisseur.ajouterProduit(Produits[0]);
    fournisseur.ajouterProduit( Produits[1]);
    fournisseur.ajouterProduit (Produits[2]);
   // vérifier l'ajout des produits
    if (fournisseur.getCatalogue().size() == 3) {
       points += 1.25;
    }
    else
    {
        cout << "\033[31m" << "La méthode ajouterProduit ne vérifie pas l'ajout d'un produit." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

     // vérifier l'ajout d'un même  produit
     fournisseur.ajouterProduit(Produits[1]);
    if (fournisseur.getCatalogue().size() == 3) {
       points += 1.25;
    }
    else
     {
        cout << "\033[31m" << "La méthode ajouterProduit ne vérifie pas l'ajout d'un même produit." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // supprimer un produit non existant
    fournisseur.supprimerProduit(Produits[3]);
    if (fournisseur.getCatalogue().size() == 3) {
       points += 1;
    }
    else
    {
        cout << "\033[31m" << "La méthode supprimerProduit ne vérifie pas la suppression d'un produit inexistant." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // supprimer un produit  existant
    fournisseur.supprimerProduit(Produits[1]);
    if (fournisseur.getCatalogue().size() == 2) {
       points += 1;
    }
    else
    {
        cout << "\033[31m" << "La méthode supprimerProduit ne vérifie pas la suppression d'un produit existant." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    //réinitialiser le catalogue
    fournisseur.reinitialiser();
    if (fournisseur.getCatalogue().size() == 0) {
       points += 1;
    }
    else
    {
        cout << "\033[31m" << "La méthode supprimerProduit ne vérifie pas la réinitialisation du calalogue." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    fournisseur.ajouterProduit(Produits[0]);
  
    //fournisseur.afficher();
    // Lire la sortie attendue
    ifstream fichier("sortieFournisseur.txt");
    string sortieAttendue((istreambuf_iterator<char>(fichier)),
        istreambuf_iterator<char>());
    //remove \r
     supprimerR(sortieAttendue);
    // Comparer la sortie attendue avec la sortie du programme
    string sortie = testing::redirect_stdout([&]() { fournisseur.afficher(); });

    if (sortieAttendue == sortie) {
        points += 1.5;
    }
    else {
        cout << "\033[31m" << "Echec du test afficherFournisseur." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    } 

    return points;
}

void lancerTests() {

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Produit." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point1 = testProduit();
    cout << "\033[32m => " << fixed << setprecision(1) << point1 << "/3.0" << "\033[0m\n";
 
    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Client." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point2 = testClient();
    cout << "\033[32m => " << fixed << setprecision(1) << point2 << "/4.0" << "\033[0m\n"; 

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Panier." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point3 = testPanier();
    cout << "\033[32m => " << fixed << setprecision(1) << point3 << "/6.0" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Fournisseur." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point4 = testFournisseur();
    cout << "\033[32m => " << fixed << setprecision(1) << point4 << "/7.0" << "\033[0m\n";

    cout << SEPARATEUR_2;
    cout << "Total des points: " << "\033[32m" << fixed << setprecision(1) << point1 + point2 + point3 + point4 << "/20.0" << "\033[0m" << endl;  
    cout << SEPARATEUR_2;
}
