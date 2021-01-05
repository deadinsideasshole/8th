// Copyright 2020 Dolbnin Mikhail dolbnin@protonmail.com

#ifndef INCLUDE_CLIENT_HPP_
#define INCLUDE_CLIENT_HPP_

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/lexical_cast.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

namespace beast = boost::beast;  // from <boost/beast.hpp>
namespace http = beast::http;    // from <boost/beast/http.hpp>
namespace net = boost::asio;     // from <boost/asio.hpp>
using tcp = net::ip::tcp;

class Client {
 public:
  Client(int num, char **param);
  int clientRequest();

 private:
  int argc;
  char **argv;
};

#endif  // INCLUDE_CLIENT_HPP_
