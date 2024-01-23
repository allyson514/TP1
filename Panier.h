
//  panier.cpp
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//
#ifndef PANIER_H
#define PANIER_H
#include <string>
#include "Produit.h"
#include <vector>
#include <iostream>
using namespace std;
class Panier
{
public:
    Panier ();
    // methodes d'accès
    vector<Produit *>  getContenuPanier()const;
    int  getNombreContenuPanier() const;
    double  getTotalAPayer() const;  
    // méthodes de modification
    
    // autres méthodes
    void ajouterProduit (Produit * prod);
    void supprimerProduit (Produit * prod);
    bool chercherProduit(Produit * prod);
    void livrerPanier();
    void afficher() const;
private:  
    vector<Produit *> contenuPanier_;  
    double totalAPayer_;
};

#endif

