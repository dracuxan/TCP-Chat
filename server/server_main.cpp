// server.cpp
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <unistd.h>

int main() {
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in server_addr{}, client_addr{};

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(12345);

  bind(server_fd, (sockaddr *)&server_addr, sizeof(server_addr));
  listen(server_fd, 1);

  socklen_t client_len = sizeof(client_addr);
  int client_sock = accept(server_fd, (sockaddr *)&client_addr, &client_len);

  char buffer[1024];
  while (true) {
    int bytes = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes <= 0)
      break;
    buffer[bytes] = '\0';
    std::cout << "Client: " << buffer << "\n";

    std::string reply;
    std::cout << "Reply: ";
    std::getline(std::cin, reply);
    send(client_sock, reply.c_str(), reply.size(), 0);
  }

  close(client_sock);
  close(server_fd);
  return 0;
}
