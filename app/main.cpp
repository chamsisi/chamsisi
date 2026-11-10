#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <iomanip>
#include <string>

#include "uincampus/version.hpp"
#include "uincampus/regles.hpp"
#include "uincampus/saisie.hpp"

int main()
{
    std::cout << "UIN-Campus - Statistiques des notes\n";
    std::cout << "Version " << uin::version() << '\n';
    std::string nomUE = uin::lireTexte("Nom de l'UE : ");

    int nombreEtudiants = uin::lireNombreEtudiants();
     
std::vector<double> notes;

    notes.reserve(static_cast<std::size_t>(nombreEtudiants));
for (int i = 1; i <= nombreEtudiants; ++i) {
        double note = uin::lireNote(i);
        notes.push_back(note);
    }
double minimum = notes[0];
    double maximum = notes[0];
    double somme = 0.0;

    int nombreAdmis = 0;

    std::array<int, 5> compteurs{};
     for (double note : notes) {

        if (note < minimum) {
            minimum = note;
        }

        if (note > maximum) {
            maximum = note;
        }

        somme += note;

        if (note >= uin::seuilValidation) {
            ++nombreAdmis;
        }

        uin::Mention mention = uin::mentionPour(note);

        std::size_t indice = static_cast<std::size_t>(mention);

        ++compteurs[indice];
    }
double moyenne = somme / nombreEtudiants; 

double sommeCarres = 0.0;

    for (double note : notes) {
        double difference = note - moyenne;
        sommeCarres += difference * difference;

    }

    double ecartType = std::sqrt(sommeCarres / nombreEtudiants);
double pourcentageAdmis = (static_cast<double>(nombreAdmis) / nombreEtudiants) * 100.0;
std::cout << "\n===== RESULTATS : " << nomUE << " =====\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Note minimale : " << minimum << '\n';
    std::cout << "Note maximale : " << maximum << '\n';
    std::cout << "Moyenne : " << moyenne << '\n';
    std::cout << "Ecart-type : " << ecartType << '\n';

    std::cout << "Nombre d'admis : " << nombreAdmis << '\n';

    std::cout << "Pourcentage des admis : "
              << std::setprecision(1)
              << pourcentageAdmis << " %\n";
std::cout << "\n===== HISTOGRAMME DES MENTIONS =====\n";

    std::array<uin::Mention, 5> mentions{
        uin::Mention::Ajourne,
        uin::Mention::Passable,
        uin::Mention::AssezBien,
        uin::Mention::Bien,
        uin::Mention::TresBien
    };

    for (uin::Mention mention : mentions) {
        std::size_t indice = static_cast<std::size_t>(mention);

        std::cout << uin::libelle(mention) << " : "
                  << std::string(
                         static_cast<std::size_t>(compteurs[indice]), '*')
                  << " (" << compteurs[indice] << ")\n";
    }
    return 0;
}

