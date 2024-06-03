# C++ Simple Web Server

A simple, scalable web server built using C++ and Boost.Asio. This project demonstrates how to set up a basic web server that can be expanded with additional features as needed.

## Description

The C++ Simple Web Server is designed to provide a basic, easy-to-understand foundation for creating a web server using C++. It utilizes the Boost.Asio library for asynchronous input/output operations and aims to be a starting point for learning about server development and network programming in C++.

## Features

- Basic HTTP server functionality
- Multi-threaded request handling
- Simple, clear, and extendable codebase

## Requirements

- C++17 or higher
- CMake 3.10 or higher
- Boost libraries (especially Boost.Asio)
- OpenSSL (for future SSL/TLS support)

## Installation

1. **Install Dependencies**
Ensure you have Homebrew installed. Then run:

```bash
brew install boost
brew install cmake
brew install openssl
``` 

2. **Clone the Repository**

```bash
git clone https://github.com/cogito21g/cpp_web_server.git
cd cpp-simple-web-server
```

3. **Build the Project**

```bash
mkdir build
cd build
cmake ..
make
```

## Usage
Run the server by specifying the port number

```bash
./SimpleWebServer 8080
```

Replace 8080 with any port number you prefer.


## Project Structure

```
cpp-simple-web-server/
├── CMakeLists.txt
├── LICENSE
├── README.md
├── www/
│   └── index.html
└── src/
    └── main.cpp
```

## Future Work
- Implement full HTTP protocol support.
- Add thread pool for better concurrency handling.
- Integrate SSL/TLS for secure communication.
- Add logging and monitoring features.

## Contributing
Contributions are welcome! Please fork the repository and submit pull requests.

## License
This project is licensed under the MIT License. See the LICENSE file for details.