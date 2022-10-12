#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr, cli_addr;
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // bind function
    bind(net_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    listen(net_socket, 10);
    char str[200], data[201];
    int fd, c;

    while (1) {
        fd = accept(net_socket, (struct sockaddr *)&cli_addr, &c);

        while (1) {
            int k = recv(fd, str, 199, 0);
            if (k == 0)
                break;
            str[k] = '\0';
            printf("recived from client: %s\n", str);
            scanf("%s", data);
            write(fd, data, strlen(data));
        }
        close(fd);
    }
    
    return 0;
}
