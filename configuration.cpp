
#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    
    string cheminFichier;
    string utilisateur;
    string motDePasse;

  
    Configuration() {
        cheminFichier = "C:/data/config.txt";
        utilisateur = "admin";
        motDePasse = "12346";
    }

public:
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void afficherParametres() const {
        cout << "Chemin : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe : " << motDePasse << endl;
    }

    void modifierUtilisateur(string nom) {
        utilisateur = nom;
    }
};

int main() {

    
    Configuration& c1 = Configuration::getInstance();

    cout << "Configuration initiale :" << endl;
    c1.afficherParametres();

    cout << "Modification de l'utilisateur :" << endl;

    c1.modifierUtilisateur("Maryam");

  
    Configuration& c2 = Configuration::getInstance();

    c2.afficherParametres();


    if (&c1 == &c2) {
        cout << "Les deux references utilisent la meme instance."
             << endl;
    }

    return 0;
}
