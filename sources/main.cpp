// Copyright 2021 roman <roman.sekin.90@mail.ru>

#include <Client.hpp>

int main(int argc, [[maybe_unused]] char **argv) {
  Client A(argc, argv);
  return A.clientRequest();
}
