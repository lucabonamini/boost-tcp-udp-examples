#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>

#include <iostream>

int main() {
  try {
    uint16_t port = 15001;

    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket socket(io_context);
    boost::asio::ip::tcp::acceptor acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
    acceptor.accept(socket);

    for(;;) {
      char buffer[65536];
      boost::system::error_code error_code;
      size_t byte_buffered = socket.read_some(boost::asio::buffer(buffer));
      std::cout << "Message from Client: " << buffer << std::endl; 
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}