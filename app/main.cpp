//
// Created by fumosoft on 9/19/2024.
//

#include <iostream>
#include <expected>
#include <string>

using namespace std::string_literals;
auto is_even(int i) -> std::expected<double, std::string> {
  if(i % 2 == 0) return 1.0;

  return std::unexpected{"This is not an even number"s};
}

int main(int argc, char** argv) {
  std::cout << "Hello World!\n";

  if(auto const num = is_even(2); num.has_value()) {
    std::cout << "The number is " << num.value() << "\n";
  }

  if(auto const num = is_even(1); !num.has_value()) {
    std::cout << num.error() << "\n";
  }

  return 0;
}