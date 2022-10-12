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
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    connect(net_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    char str[200], data[200];
    int n;

    while (1) {
        scanf("%s", data);
        write(net_socket, data, strlen(data));
        n = recv(net_socket, str, 199, 0);
        str[n] = '\0';
        printf("recieved from server: %s\n", str);
    }

    close(net_socket);

    return 0;
}
