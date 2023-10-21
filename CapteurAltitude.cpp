#include <iostream>
#include <chrono>
#include <thread>

class CapteurAltitude {
public:
    double lireAltitude() {
        // Simuler la lecture de l'altitude (en mètres) depuis un capteur.
        return altitudeSimulée;
    }

    void simulerAltitude(double altitude) {
        altitudeSimulée = altitude;
    }

private:
    double altitudeSimulée = 0.0;
};

int main() {
    CapteurAltitude capteur;

    double temps = 0.0; // Temps écoulé en secondes
    double altitude = 0.0; // Altitude actuelle en mètres

    while (temps <= 600.0) { // Simuler une période de vol de 10 minutes
        // Simuler l'augmentation de l'altitude en fonction du temps
        altitude = temps * 10.0; // Exemple d'augmentation linéaire de l'altitude

        // Simuler la lecture de l'altitude depuis un capteur
        capteur.simulerAltitude(altitude);

        // Lire l'altitude actuelle depuis le capteur
        double altitudeActuelle = capteur.lireAltitude();

        // Afficher l'altitude actuelle
        std::cout << "Temps : " << temps << " s | Altitude : " << altitudeActuelle << " m" << std::endl;

        // Pause (simulation d'une boucle de contrôle périodique)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Pause d'une seconde
        temps += 1.0; // Incrémente le temps de 1 seconde
    }

    return 0;
}
