
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;


class StrategieTri {
public:
    virtual void trier(vector<string>& mots) = 0;
    virtual ~StrategieTri() {}
};


class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& mots) override {
        sort(mots.begin(), mots.end());
    }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& mots) override {
        sort(mots.begin(), mots.end(), greater<string>());
    }
};


class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& mots) override {
        sort(mots.begin(), mots.end(),
             [](string a, string b) {
                 return a.length() < b.length();
             });
    }
};


class GestionnaireTri {
private:
    unique_ptr<StrategieTri> strategie;

public:
    
    void definirStrategie(unique_ptr<StrategieTri> s) {
        strategie = move(s);
    }

   
    void effectuerTri(vector<string>& mots) {
        if (strategie == nullptr) {
            cout << "Aucune strategie definie !" << endl;
            return;
        }

        strategie->trier(mots);
    }
};


void afficher(const vector<string>& mots) {
    for (const string& mot : mots) {
        cout << mot << " ";
    }

    cout << endl;
}

int main() {

    vector<string> mots = {
        "Banane", "Pomme", "Kiwi", "Orange", "Ananas"
    };

    GestionnaireTri gestionnaire;

    cout << "Liste initiale :" << endl;
    afficher(mots);

    
    gestionnaire.definirStrategie(make_unique<TriCroissant>());

    gestionnaire.effectuerTri(mots);

    cout << "Tri croissant :" << endl;
    afficher(mots);

    
    gestionnaire.definirStrategie(make_unique<TriDecroissant>());

    gestionnaire.effectuerTri(mots);

    cout << "\nTri decroissant :" << endl;
    afficher(mots);

  
    gestionnaire.definirStrategie(make_unique<TriParLongueur>());

    gestionnaire.effectuerTri(mots);

    cout << "Tri par longueur :" << endl;
    afficher(mots);

    return 0;
}
