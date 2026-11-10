#include "uincampus/version.hpp"
#include <iostream>

auto main() -> int {
  std::cout << "UIN-Campus — Système de gestion académique\n";
  std::cout << "Version " << uin::version() << '\n';

  return 0;
}
