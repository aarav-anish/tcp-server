#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

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

    return 0;
}