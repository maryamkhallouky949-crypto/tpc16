
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Forme {
public:
    virtual void afficher() const = 0;

    virtual ~Forme() {}
};

class Cercle : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Cercle." << endl;
    }
};


class Carre : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Carre." << endl;
    }
};


class Triangle : public Forme {
public:
    void afficher() const override {
        cout << "Je suis un Triangle." << endl;
    }
};


class FabriqueForme {
public:
    static Forme* creerForme(string type) {

        if (type == "cercle") {
            return new Cercle();
        }
        else if (type == "carre") {
            return new Carre();
        }
        else if (type == "triangle") {
            return new Triangle();
        }
        else {
            throw invalid_argument("Type de forme inconnu !");
        }
    }
};

int main() {

    Forme* f1 = nullptr;
    Forme* f2 = nullptr;
    Forme* f3 = nullptr;

    try {
        f1 = FabriqueForme::creerForme("cercle");
        f2 = FabriqueForme::creerForme("carre");
        f3 = FabriqueForme::creerForme("triangle");

        f1->afficher();
        f2->afficher();
        f3->afficher();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }


    delete f1;
    delete f2;
    delete f3;

    return 0;
}
