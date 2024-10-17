#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define ADDRESS "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
	int master_socket;
	char buffer[BUFFER_SIZE];
	
	struct sockaddr_in serv_addr;
	
	memset(&serv_addr, 0, sizeof(serv_addr));
		
	if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		printf("[ERROR] CAN'T CREATE SOCKET\n");
		return 1;
	}
	
	// assign IP, PORT
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, ADDRESS, &serv_addr.sin_addr) == -1) {
		printf("[ERROR] INVALID ADDRESS/ ADDRESS NOT SUPPORTED\n");
		return 1;
	}
	
	// connect
	if (connect(master_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
		printf("[ERROR] CAN'T CONNECT TO THE HOST %s:%d\n", ADDRESS, PORT);
		return 1;
	}
	
	while (1) {
		printf("[TCP]> ");
		scanf("%1023s", buffer);
		
		if (strcmp(buffer, "exit") == 0) {
			printf("exited...\n");
			break;
		}
		
		if (send(master_socket, buffer, strlen(buffer), 0) > 0) {
        	printf("[SEND] %s\n", buffer);
        } else {
        	printf("[WARNING ] CAN'T SEND TO THE SERVER!\n");
        }
		
		if (recv(master_socket, buffer, BUFFER_SIZE, 0) > 0) {
			printf("[RECEIVE] %s\n", buffer);
			memset(buffer, 0, BUFFER_SIZE);
		} else {
			printf("[ERROR] CAN'T READ SERVER RESPONSE\n");
		}
	}
		
	// close connection
	close(master_socket);
	return 0; 
}