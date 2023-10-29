#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 12345
int main()
{
	int sock,n,connfd;
	char buffer[1024];
	struct sockaddr_in sadd;
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("error insocket");
		exit(-1);
	}
	printf("Socket created successfully\n");
	sadd.sin_family=AF_INET;
	sadd.sin_port=htons(PORT);
	sadd.sin_addr.s_addr=inet_addr("127.0.0.1");
	//inet_pton(AF_INET,"127.0.0.1",&sadd.sin_addr);
	socklen_t len;
	len=sizeof(sadd);
	if(connect(sock,(struct sockaddr *)&sadd,len)!=0)
	{
		printf("Connection with the server failed");
		exit(0);
	}
	int bit=0,ack;
	for(;;)
	{
		printf("Enter message for frame %d: ",bit);
		scanf("%s",buffer);
		write(sock,buffer,sizeof(buffer));
		write(sock,&bit,sizeof(bit));
		if(strncmp(buffer,"exit",4)==0)
		{	
			break;
		}
		read(sock,&ack,sizeof(ack));
		if(bit==ack)
		{
			printf("Restransmit! ");
		}
		else
		{
			printf("Ack received\n");
			bit=ack;
		}
		
		
	}
	close(sock);
	return 0;
}
