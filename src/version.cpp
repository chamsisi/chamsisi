#include "uincampus/version.hpp"

#ifndef UIN_VERSION
#define UIN_VERSION "0.1.0"
#endif

namespace uin {
auto version() -> std::string_view { return UIN_VERSION; }
} // namespace uin
