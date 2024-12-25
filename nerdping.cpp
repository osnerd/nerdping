#include <iostream>
#include <iomanip>
#include <string>
#include <thread> 
#include <chrono>  
#include <cstdlib>  
#include <sstream> 

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

void print_with_color(const std::string& message, const std::string& color_code) {
    std::cout << "\033[" << color_code << "m" << message << "\033[0m";
}

// simulated socket based ping (SIMULATED. NOT AN ACTUAL PING.)
void custom_ping(const std::string& ip, int port) {
    while (true) {
        int bytes = 64;
        int ttl = 128;
        int time = rand() % 100 + 1;

        std::ostringstream formatted_output;
        formatted_output << "(IP: " << ip
            << ") | Bytes: " << bytes
            << " | TTL: " << ttl
            << " | TIME: " << time << "ms"
            << " | Port: " << port;

        print_with_color(formatted_output.str(), "32"); 
        std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void print_ascii_art() {
    std::string art = R"(
 _______                   ._____________.__                
 \      \   ___________  __| _/\______   \__| ____    ____  
 /   |   \_/ __ \_  __ \/ __ |  |     ___/  |/    \  / ___\ 
/    |    \  ___/|  | \/ /_/ |  |    |   |  |   |  \/ /_/  >
\____|__  /\___  >__|  \____ |  |____|   |__|___|  /\___  / 
        \/     \/           \/                   \//_____/  
)";
    print_with_color(art, "34");
    std::cout << std::endl;
}

int main() {
    std::string ip;
    int port;
    print_ascii_art();
    print_with_color("[", "90"); 
    print_with_color(">", "36"); 
    print_with_color("] ", "90");
    print_with_color("Enter IP address: ", "35");
    std::getline(std::cin, ip); 
    print_with_color("[", "90");
    print_with_color(">", "36");
    print_with_color("] ", "90");
    print_with_color("Enter Port: ", "35");
    std::cin >> port;
    custom_ping(ip, port);

    return 0;
}
