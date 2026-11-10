#pragma once

#include <string_view>

namespace uin {

/// Bornes du barème et seuil de validation d'une UE.
inline constexpr double noteMin = 0.0;
inline constexpr double noteMax = 20.0;
inline constexpr double seuilValidation = 10.0;

/// Mentions attribuées selon la moyenne.
enum class Mention {
    Ajourne,
    Passable,
    AssezBien,
    Bien,
    TresBien
};

/// Vérifie si une note est comprise entre 0 et 20.
constexpr bool estNoteValide(double note)
{
    return note >= noteMin && note <= noteMax;
}

/// Mention correspondant à une moyenne.
Mention mentionPour(double moyenne);

/// Libellé affichable d'une mention.
std::string_view libelle(Mention mention);

} // namespace uin

