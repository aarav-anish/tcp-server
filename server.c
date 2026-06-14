#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main()
{
    int s, c;
    socklen_t addrlen;

    struct sockaddr_in srv, cli;

    memset(&srv, 0, sizeof(srv));
    memset(&cli, 0, sizeof(cli));

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0)
    {
        printf("Socket() error");
        return -1;
    }

    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = 0;
    srv.sin_port = htons(PORT);

    if (bind(s, (struct sockaddr *)&srv, sizeof(srv)))
    {
        printf("bind() error");
        return -1;
    }

    return 0;
}