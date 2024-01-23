
//  client.h
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "Panier.h"
using namespace std;
class Client
{
public:
    Client (const string & nom="",  const string & prenom="", 
    int identifiant= 0, const string & codePostal = "");
    ~Client();
    // methodes d'acces   
    string  getNom() const;
    string  getPrenom() const;
    int  getIdentifiant() const;
    string  getCodePostal() const;
    Panier *  getPanier () const;  
    // methodes de modification
    void  setNom(const string &nom) ;
    void  setPrenom(const string  & prenom) ;
    void  setIdentifiant(int identifiant) ;
    void  setCodePostal(const string  & codePostal);
      
    // autres méthodes
    void acheterProduit (Produit * prod);
    void supprimerProduit(Produit *);
    void livrerPanier();  
     void afficher()const;
private:
    
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
    Panier *  monPanier_;
};
#endif /* client_h */
