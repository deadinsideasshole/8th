// Copyright 2020 ivan <ikhonyak@gmail.com>

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

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
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
