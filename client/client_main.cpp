// client.cpp
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <string>
#include <unistd.h>

int main() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in server_addr{};

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(12345);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  if (connect(sock, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    std::cerr << "Connection failed\n";
    return 1;
  }

  std::string message;
  char buffer[1024];
  while (true) {
    std::cout << "You: ";
    std::getline(std::cin, message);
    send(sock, message.c_str(), message.size(), 0);

    int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes <= 0)
      break;
    buffer[bytes] = '\0';
    std::cout << "Server: " << buffer << "\n";
  }

  close(sock);
  return 0;
}
