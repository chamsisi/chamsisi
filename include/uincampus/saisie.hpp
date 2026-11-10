#pragma once

#include <string>
#include <string_view>

namespace uin {

int lireNombreEtudiants();

double lireNote(int numeroEtudiant);

std::string lireTexte(std::string_view message);

}
