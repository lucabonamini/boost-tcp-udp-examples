#include <boost/asio.hpp>
#include <boost/array.hpp>

#include <iostream>

int main() {
  try {
    uint16_t port = 15001;

    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket socket(io_context);
    socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), port));

    const std::string msg = "Hello from Client!";
    boost::system::error_code error_code;

    for(;;) {
      boost::asio::write(socket, boost::asio::buffer(msg), error_code);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
