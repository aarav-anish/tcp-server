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

    addrlen = 0;
    memset(&srv, 0, sizeof(srv));
    memset(&cli, 0, sizeof(cli));

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0)
    {
        printf("Socket() error\n");
        return -1;
    }
    printf("Socket initialized\n");

    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = 0;
    srv.sin_port = htons(PORT);

    if (bind(s, (struct sockaddr *)&srv, sizeof(srv)))
    {
        printf("bind() error\n");
        close(s);

        return -1;
    }
    printf("Bind server side\n");

    int queue = 5;
    if (listen(s, queue))
    {
        printf("listen() error\n");
        close(s);

        return -1;
    }
    printf("Listening on 0.0.0.0:%d\n", PORT);

    c = accept(s, (struct sockaddr *)&srv, &addrlen);
    if (c < 0)
    {
        printf("accept() error\n");
        close(s);

        return -1;
    }
    printf("Client connected\n");

    return 0;
}