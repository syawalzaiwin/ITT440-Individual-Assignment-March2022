#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8888

int main(int argc, char const* argv[])
{
    int sock = 0, client_fd, num=0;
    struct sockaddr_in serv_addr;
    char result[200];
    char name[200];
    char pattern[190] =
{
   ' ', '!', '"', '#',  '$', '%',  '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
   '4', '5', '6',  '7', '8', '9', ':',  ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F',
   'G', 'H', 'I',  'J', 'K', 'L', 'M',  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
   'Z', '[', '\\', ']', '^', '_', '`',  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
   'm', 'n', 'o',  'p', 'q', 'r', 's',  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', ' ',
   '!', '"', '#',  '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
   '4', '5', '6',  '7', '8', '9', ':',  ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F',
   'G', 'H', 'I',  'J', 'K', 'L', 'M',  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
   'Z', '[', '\\', ']', '^', '_', '`',  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
   'm', 'n', 'o',  'p', 'q', 'r', 's',  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~' 
};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "192.168.56.109", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((client_fd
         = connect(sock, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    printf("Enter Your Email: ");
    scanf("%s", name);
    printf("\n");
    send(sock, name, strlen(name), 0);

    read(sock, result, 200);

    num=atoi(result);

	for(int j = 0; j < num; j++)
	{
		for(int i = 0; i < 72; i++){
		printf("%c" , pattern[i]);}

		printf("\n");

		for(int k = 0; k < 189; k++)
		{
	    		char temp = pattern[k+1];
	    		pattern[k+1] = pattern[k];
	    		pattern[k]=temp;
		}
	}

    close(client_fd);
    return 0;
}
