
#include <iostream>
#include <vector>
using namespace std;


class Observateur {
public:
    virtual void mettreAJour(
        float temperature,
        float humidite,
        float pression
    ) = 0;

    virtual ~Observateur() {}
};

class StationMeteo {
private:
    float temperature;
    float humidite;
    float pression;

    vector<Observateur*> observateurs;

public:
   
    void ajouterObservateur(Observateur* o) {
        observateurs.push_back(o);
    }

    
    void supprimerObservateur(Observateur* o) {
        for (int i = 0; i < observateurs.size(); i++) {
            if (observateurs[i] == o) {
                observateurs.erase(observateurs.begin() + i);
                return;
            }
        }
    }

    void notifierObservateurs() {
        for (Observateur* o : observateurs) {
            o->mettreAJour(temperature, humidite, pression);
        }
    }

   
    void modifierDonnees(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;

        notifierObservateurs();
    }
};


class AffichageTemperature : public Observateur {
public:
    void mettreAJour(
        float temperature,
        float humidite,
        float pression
    ) override {
        cout << "Temperature : " << temperature << " C" << endl;
    }
};


class AffichageHumidite : public Observateur {
public:
    void mettreAJour(
        float temperature,
        float humidite,
        float pression
    ) override {
        cout << "Humidite : " << humidite << " %" << endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(
        float temperature,
        float humidite,
        float pression
    ) override {
        cout << "Pression : " << pression << " hPa" << endl;
    }
};

int main() {

    StationMeteo station;

    AffichageTemperature affichageT;
    AffichageHumidite affichageH;
    AffichagePression affichageP;

    
    station.ajouterObservateur(&affichageT);
    station.ajouterObservateur(&affichageH);
    station.ajouterObservateur(&affichageP);

    cout << " Premier changement meteo " << endl;

    station.modifierDonnees(25.5, 60, 1013);

    cout << " Deuxieme changement meteo " << endl;

    station.modifierDonnees(30, 45, 1010);

    station.supprimerObservateur(&affichageH);

    cout << " Apres suppression de l'affichage humidite "
         << endl;

    station.modifierDonnees(22, 70, 1015);

    return 0;
}
