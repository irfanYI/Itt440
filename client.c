#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main() {

	int clientSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;

	/*--create the socket, the three arguments are: --*/
	/* 1)internet doma*in 2)stream socket 3)default protocol(tcp in this case)*/

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);

	/*--config settings of the erver address struct--*/
	/*--address family = internet --*/
	
	serverAddr.sin_family = AF_INET;

	/*--set port number, using htons function to use proper byte order--*/

	serverAddr.sin_port = htons(7891);

	/*--set ip ad6dress to localhost--*/

	serverAddr.sin_addr.s_addr = inet_addr("192.168.24.128");

	/*--set all bits of the padding field to 0--*/

	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	/*--connect the socket to the server using the address struct--*/

	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

	/*--read the message from the server into the buffer--*/
	recv(clientSocket,buffer,1024,0);

	/*--print the received message--*/
	printf("Data reveiced : %s",buffer);

	return 0;

}
