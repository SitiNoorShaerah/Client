#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int clientSock;
	char message[1000];
	struct sockaddr_in servAddr;
	socklen_t  addrSize;

	clientSock = socket(AF_INET, SOCK_STREAM, 0);
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(36772);
	servAddr.sin_addr.s_addr = inet_addr("192.168.73.129");
	memset(servAddr.sin_zero, '\0', sizeof servAddr.sin_zero);
	addrSize = sizeof servAddr;
	connect(clientSock, (struct sockaddr *) & servAddr, addrSize);
	
	while(1)
	{
		printf("Start your conversation:   " ,  message );
		scanf("%s", message);


		char w[] = "Quit";
		
		send(clientSock, message, 100, 0);
		recv(clientSock, message, 100, 0);

		printf("Server replied:%s\n"  , message);

		if(strcasecmp(message, w)==0)
		{
			break;
		
		}
		else;}
		close(clientSock);
		return 0;

	

}
