
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    Contact(string n) {
        nom = n;
        telephone = "";
        email = "";
    }

    Contact(string n, string t) {
        nom = n;
        telephone = t;
        email = "";
    }

    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    void afficher() const {
        cout << "Nom : " << nom << endl;
        if (!telephone.empty()) cout << "Téléphone : " << telephone << endl;
        if (!email.empty()) cout << "Email : " << email << endl;
        cout << "------------------" << endl;
    }
};

int main() {
    Contact c1("Alice");
    Contact c2("Bob", "0601020304");
    Contact c3("Charlie", "0605060708", "charlie@example.com");

    c1.afficher();
    c2.afficher();
    c3.afficher();

    return 0;
}
