#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#define MAX 80
#define SA struct sockaddr
	void  func(int sock)
	{
		char b[MAX];
		int x;
		for(;;)
		{
			bzero(b,sizeof(b));
			printf("Enter the string : \n");
			x=0;
			while((b[x++]=getchar())!='\n');
			write(sock, b, sizeof(b));
			bzero(b,sizeof(b));
			read(sock, b, sizeof(b));
			printf("From server :%s" , b);

		if((strncmp(b, "Asalamualaikum", 14)) == 0)
		{
			printf("Enter the string: Waalaikumsalam\n");
			read(sock,b, sizeof(b));
			printf("From server : %s", b);
		}
		
	}
}

int main()
{
int sock, conn;
struct sockaddr_in servaddr, cli;
sock=socket(AF_INET, SOCK_STREAM, 0);

if(sock==-1)
{
	printf("Socket creation failed...\n");	
	exit(0);
	}
	else
		printf("Socket successfully created.\n");
		bzero(&servaddr, sizeof(servaddr));
			servaddr.sin_family=AF_INET;
			servaddr.sin_addr.s_addr=inet_addr("192.168.92.128");
			servaddr.sin_port=htons(36772);
		if(connect(sock,(SA*)&servaddr, sizeof(servaddr))!=0)
	{
	printf("Connection with the server failed...\n");
		exit(0);
		}
		else 
			printf("Connected to the server...\n");
			func(sock);
		close(sock);
	}
 # ClientServer
 # Client
 # Client
