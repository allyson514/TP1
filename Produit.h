#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

using namespace std;
class Produit
{
  public:
    Produit(const string &nom = "outil",
            int categorie = 0, double prix = 0.0);

    string getNom() const;
    int  getCategorie() const;
    double  getPrix() const;
    
    void  setNom(const string &nom);
    void  setCategorie(int categorie);
    void  setPrix(double prix);
    
    void afficher() const;
  private:
    string nom_;
    int categorie_;
    double prix_;
};

#endif
