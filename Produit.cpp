#include "Produit.h"
#include "Fournisseur.h"
#include <iostream>
#include <string>
#include <iomanip>

Produit::Produit(const string &nom, int categorie, double prix) {
	nom_ = nom;
	categorie_ = categorie;
	prix_ = prix;
}

string Produit::getNom() const{
	return nom_;
}

int Produit::getCategorie() const {
	return categorie_;
}

double Produit::getPrix() const {
	return prix_;
}

void Produit::setNom(const string& nom) {
	nom_ = nom;
}

void Produit::setCategorie(int categorie) {
	categorie_ = categorie;
}

void Produit::setPrix(double prix) {
	prix_ = prix;
}

void Produit::afficher() const {
	cout << nom_ << "\nCatégorie: " << categorie_ << "\nPrix: $" << prix_ << endl;
}