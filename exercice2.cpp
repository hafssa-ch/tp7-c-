
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Article {
    string nom;
    double prixUnitaire;
    int quantite;
    double tva;
};

class Facture {
private:
    vector<Article> articles;

public:
    void ajouterArticle(const string& nom, double prixUnitaire) {
        Article a = {nom, prixUnitaire, 1, 0.2}; // TVA par défaut 20%
        articles.push_back(a);
    }

    void ajouterArticle(const string& nom, double prixUnitaire, int quantite) {
        Article a = {nom, prixUnitaire, quantite, 0.2};
        articles.push_back(a);
    }

    void ajouterArticle(const string& nom, double prixUnitaire, int quantite, double tva) {
        Article a = {nom, prixUnitaire, quantite, tva};
        articles.push_back(a);
    }

    void afficherTotal() const {
        double total = 0.0;
        for (const auto& a : articles) {
            total += a.prixUnitaire * a.quantite * (1 + a.tva);
        }
        cout << "Total de la facture : " << total << " €" << endl;
    }
};

int main() {
    Facture f;
    f.ajouterArticle("Stylo", 1.5);
    f.ajouterArticle("Cahier", 2.0, 3);
    f.ajouterArticle("Calculatrice", 50.0, 2, 0.1); // TVA 10%

    f.afficherTotal();

    return 0;
}
