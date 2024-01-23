#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Fournisseur 
{
  public:
    Fournisseur(const string & nom="");

    string  getNom() const;
    vector<Produit *>  getCatalogue() const;
     
    void ajouterProduit(Produit *produit);
    void supprimerProduit(Produit *produit);
    void reinitialiser(); 
    
    void afficher() const;    

  private:
    string nom_;
    vector<Produit *> catalogue_;
};

#endif
