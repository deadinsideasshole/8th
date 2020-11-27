// Copyright 2020 Dolbnin Mikhail dolbnin@protonmail.com

#include "Client.hpp"

Client::Client(int argc, char **argv) {
  this->argc = argc;
  this->argv = argv;
}

int Client::clientRequest() {
  try {
    if (argc != 5 && argc != 6) {
      std::cerr
          << "Usage: <host> <port> <target> <HTTP version: 1.1(default)>\n";
      return EXIT_FAILURE;
    }
    auto const host = argv[1];
    auto const port = argv[2];
    auto const target = argv[3];
    auto const data = argv[4];
    int version = argc == 6 && !std::strcmp("1.0", argv[5]) ? 10 : 11;

    net::io_context ioc;

    tcp::resolver resolver(ioc);
    beast::tcp_stream stream(ioc);

    auto const results = resolver.resolve(host, port);

    stream.connect(results);
    http::request<http::string_body> req{http::verb::post, target, version};
    req.set(http::field::host, host);
    req.body() = data;
    req.prepare_payload();
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::content_type, "application/json");
    http::write(stream, req);

    beast::flat_buffer buffer;

    http::response<http::dynamic_body> res;

    http::read(stream, buffer, res);

    std::cout << res << std::endl;

    beast::error_code ec;
    stream.socket().shutdown(tcp::socket::shutdown_both, ec);

    if (ec && ec != beast::errc::not_connected) throw beast::system_error{ec};
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return 0;
}
