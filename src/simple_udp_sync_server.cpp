#include <boost/asio.hpp>

#include <iostream>

int main() {
    try {
        uint16_t port = 15001;

        boost::asio::io_context io_context;
        boost::asio::ip::udp::endpoint receiver(boost::asio::ip::udp::v4(), port);
        boost::asio::ip::udp::socket socket(io_context, receiver);

        for(;;) {
            char buffer[65536];
            boost::asio::ip::udp::endpoint sender;
            size_t bytes_transferred = socket.receive_from(boost::asio::buffer(buffer), sender);
            std::cout << sender << ": " << buffer << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
