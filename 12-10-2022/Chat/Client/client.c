#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in serv_addr, cli_addr;
    return 0;
}
