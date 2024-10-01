//
// Created by fumosoft on 9/19/2024.
//

#include <fmt/os.h>
#include <docopt/docopt.h>
#include <string>
#include <expected>

using namespace std::string_literals;
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

std::expected<void, std::string> validate_project_name(std::string_view project_name) {
  fmt::print("Validing project name.");
  for(auto iter = project_name.begin(); iter != project_name.end(); iter = std::next(iter)) {
    if(*iter == '.') {
      if(*std::next(iter) == '.') {
        return std::unexpected("Project name must not contain `..`"s);
      }
    }

    if(*iter == '\\') {
      return std::unexpected(R"(Project name must not contain `\`)"s);
    }
  }

  return {};
}

[[nodiscard]]std::expected<void, std::string> create_new_proj(std::string_view project_name) {
  if(project_name.length() > 20) return std::unexpected("Project name too long"s);

  if(auto const maybe = validate_project_name(project_name); !maybe.has_value()) return maybe;

  return {};
}

int main(int const argc, char** argv) {
  auto const args = docopt::docopt(USAGE,
    {argv + 1, argv + argc},
    true,
    "mkproj version 1.0");

  if(args.contains("new") || args.contains("create")) {
    auto const project_name = args.at("<name>").asString();
    if(auto const maybe = create_new_proj(project_name); !maybe.has_value()) {
      fmt::print("Failed to create new project {}. Reason: {}\n", project_name, maybe.error());
    }
  }

  return 0;
}