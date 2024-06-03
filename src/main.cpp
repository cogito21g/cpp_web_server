#include <boost/asio.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

using boost::asio::ip::tcp;

std::string read_file(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::string handle_request(const std::string& request) {
    std::istringstream request_stream(request);
    std::string method;
    std::string uri;
    std::string version;

    request_stream >> method >> uri >> version;

    if (method == "GET") {
        if (uri == "/") {
            uri = "/index.html";
        }

        std::string file_path = "www" + uri;
        std::string file_content = read_file(file_path);

        if (!file_content.empty()) {
            return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n" + file_content;
        } else {
            return "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
        }
    }

    return "HTTP/1.1 400 Bad Request\r\nContent-Type: text/html\r\n\r\n<html><body><h1>400 Bad Request</h1></body></html>";
}

void session(tcp::socket sock) {
    try {
        for (;;) {
            char data[1024];
            boost::system::error_code error;
            size_t length = sock.read_some(boost::asio::buffer(data), error);
            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw boost::system::system_error(error); // Some other error.

            std::string request(data, length);
            std::string response = handle_request(request);

            boost::asio::write(sock, boost::asio::buffer(response), error);
            if (error)
                throw boost::system::system_error(error);
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void server(boost::asio::io_context& io_context, short port) {
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
    for (;;) {
        tcp::socket sock(io_context);
        acceptor.accept(sock);
        std::thread(session, std::move(sock)).detach();
    }
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: CppSimpleWebServer <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;
        server(io_context, std::atoi(argv[1]));
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
