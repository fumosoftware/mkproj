//
// Created by fumosoft on 9/19/2024.
//

#include <fmt/os.h>
#include <docopt/docopt.h>

namespace {
  constexpr auto USAGE =
R"(mkproj

    Usage:
      mkproj (new | create) <name>
      mkproj (-h | --help)
      mkproj (-v | --version)
    Options:
      -h --help         Show this screen.
      -v --version      Show version.
)";
}

int main(int argc, char** argv) {
  auto args = docopt::docopt(USAGE, {argv + 1, argv + argc}, true, "mkproj version 1.0");
  fmt::print("Hello World!\n");
}