// Copyright 2020 ivan <ikhonyak@gmail.com>

#include <Client.hpp>

int main(int argc, [[maybe_unused]] char **argv) {
  Client A(argc, argv);
  return A.clientRequest();
}
