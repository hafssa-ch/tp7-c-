
#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    string titulaire;
    double solde;
    string codeSecret;

public:
    CompteBancaire(const string& nom) {
        titulaire = nom;
        solde = 0.0;
        codeSecret = "0000"; 
    }

    CompteBancaire(const string& nom, double soldeInitial) {
        titulaire = nom;
        solde = soldeInitial;
        codeSecret = "0000";
    }

    void setCodeSecret(const string& code) {
        codeSecret = code;
    }

    void afficherSolde() const {
        cout << "Titulaire : " << titulaire << ", Solde : " << solde << " €" << endl;
    }

    bool retrait(double montant) {
        if (montant <= solde && montant > 0) {
            solde -= montant;
            cout << "Retrait de " << montant << " € effectué." << endl;
            return true;
        } else {
            cout << "Retrait impossible !" << endl;
            return false;
        }
    }

    bool retrait(double montant, const string& code) {
        if (code != codeSecret) {
            cout << "Code incorrect !" << endl;
            return false;
        }
        return retrait(montant);
    }
};

int main() {
    CompteBancaire c1("Alice", 500.0);
    c1.setCodeSecret("1234");

    c1.afficherSolde();
    c1.retrait(100.0);
    c1.afficherSolde();
    c1.retrait(50.0, "1234"); 
    c1.afficherSolde();
    c1.retrait(200.0, "0000"); 
    c1.afficherSolde();

    return 0;
}
