#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CONNECTION_PORT 3500

int main()
{
int i;
int str_length;
int socket_descriptor;
int client_socket;
char storage_buffer[80];
int bytes_read=79;
int length_of_address;
int option_value=1;
struct sockaddr_in server_address;
struct sockaddr_in connection_address;
char* message= "This is a message from server";
socket_descriptor=socket(AF_INET,SOCK_STREAM,0);
if (socket_descriptor<0)
{
perror("Socket creation failed");
exit(EXIT_FAILURE);
}
int status=setsockopt(socket_descriptor,SOL_SOCKET,SO_REUSEADDR,&option_value,sizeof(option_value));
if (status<0)
{
  perror("Couldn't set options");
  exit(EXIT_FAILURE);
}
server_address.sin_family=AF_INET;
server_address.sin_port=htons(CONNECTION_PORT);
server_address.sin_addr.s_addr=INADDR_ANY;
server_address.sin_zero[8]='\0';
status=bind(socket_descriptor,(struct sockaddr*)&server_address,sizeof(struct sockaddr));
if (status<0)
{
perror("could't listen for connections");
exit(EXIT_FAILURE);
}
status=listen(socket_descriptor,4);
if(status<0) 
{
perror("couldn't listen for connections");
exit(EXIT_FAILURE);
}
length_of_address=sizeof(connection_address);
client_socket=accept(socket_descriptor, (struct sockaddr*)&connection_address,&length_of_address);
if (client_socket<0)
{
perror("couldn't establish connection with client");
exit(EXIT_FAILURE);
}
read(client_socket,storage_buffer,80);
printf("testing -----=%d\n",strlen(storage_buffer));
str_length=strlen(storage_buffer);
storage_buffer[str_length+1]='\0';
printf("Message from client %s\n",storage_buffer);
for(i=0;i<str_length;++i)
{
storage_buffer[i]=toupper(storage_buffer[i]);
}
storage_buffer[i]='\0';
  
send(client_socket,storage_buffer,strlen(storage_buffer),0);
close(socket_descriptor);
close(client_socket);
return 0;
}
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CONNECTION_PORT 3500

int main()
{
int i;
int str_length;
int socket_descriptor;
int client_socket;
char storage_buffer[80];
int bytes_read=79;
int length_of_address;
int option_value=1;
struct sockaddr_in server_address;
struct sockaddr_in connection_address;
char* message= "This is a message from server";
socket_descriptor=socket(AF_INET,SOCK_STREAM,0);
if (socket_descriptor<0)
{
perror("Socket creation failed");
exit(EXIT_FAILURE);
}
int status=setsockopt(socket_descriptor,SOL_SOCKET,SO_REUSEADDR,&option_value,sizeof(option_value));
if (status<0)
{
  perror("Couldn't set options");
  exit(EXIT_FAILURE);
}
server_address.sin_family=AF_INET;
server_address.sin_port=htons(CONNECTION_PORT);
server_address.sin_addr.s_addr=INADDR_ANY;
server_address.sin_zero[8]='\0';
status=bind(socket_descriptor,(struct sockaddr*)&server_address,sizeof(struct sockaddr));
if (status<0)
{
perror("could't listen for connections");
exit(EXIT_FAILURE);
}
status=listen(socket_descriptor,4);
if(status<0) 
{
perror("couldn't listen for connections");
exit(EXIT_FAILURE);
}
length_of_address=sizeof(connection_address);
client_socket=accept(socket_descriptor, (struct sockaddr*)&connection_address,&length_of_address);
if (client_socket<0)
{
perror("couldn't establish connection with client");
exit(EXIT_FAILURE);
}
read(client_socket,storage_buffer,80);
printf("testing -----=%d\n",strlen(storage_buffer));
str_length=strlen(storage_buffer);
storage_buffer[str_length+1]='\0';
printf("Message from client %s\n",storage_buffer);
for(i=0;i<str_length;++i)
{
storage_buffer[i]=toupper(storage_buffer[i]);
}
storage_buffer[i]='\0';
  
send(client_socket,storage_buffer,strlen(storage_buffer),0);
close(socket_descriptor);
close(client_socket);
return 0;
}

