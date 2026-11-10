#include "uincampus/saisie.hpp"
#include "uincampus/regles.hpp"

#include <iostream>
#include <limits>
#include <sstream>

namespace uin {

std::string lireTexte(std::string_view message)
{
    std::string texte;

    std::cout << message;
    std::getline(std::cin, texte);

    while (texte.empty()) {
        std::cout << "Le texte ne doit pas etre vide. Reessayez : ";
        std::getline(std::cin, texte);
    }

    return texte;
}

int lireNombreEtudiants()
{
    int nombre = 0;

    while (true) {
        std::cout << "Nombre d'etudiants (1 a 200) : ";

        if (std::cin >> nombre && nombre >= 1 && nombre <= 200) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return nombre;
        }

        std::cout << "Valeur incorrecte. Reessayez.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double lireNote(int numeroEtudiant)
{
    std::string texte;

    while (true) {
        std::cout << "Note de l'etudiant " << numeroEtudiant << " : ";
        std::getline(std::cin, texte);

        for (char& caractere : texte) {
            if (caractere == ',') {
                caractere = '.';
            }
        }

        std::istringstream saisie(texte);
        double note = 0.0;
        char reste = '\0';

        if (saisie >> note && !(saisie >> reste) && estNoteValide(note)) {
            return note;
        }

        std::cout << "Note incorrecte. Entrez une note entre 0 et 20.\n";
    }
}

}
