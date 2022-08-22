#include <boost/asio.hpp>
#include <boost/array.hpp>

#include <chrono>
#include <iostream>
#include <thread>

int main() {
  try {
    uint16_t port = 15001;

    boost::asio::io_context io_context;
    boost::asio::ip::udp::socket socket(io_context);
    socket.open(boost::asio::ip::udp::v4());

    for(;;) {
      socket.send_to(boost::asio::buffer("Hello from Client!"),
        boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), port});
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}