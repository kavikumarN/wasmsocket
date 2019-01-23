#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <emscripten.h>
#include <netinet/in.h>
int main()
{
int ls;
char buf[1000],buf1[1000];
struct sockaddr_in cli;
ls=socket(AF_INET,SOCK_STREAM,0);
cli.sin_family=AF_INET;
cli.sin_addr.s_addr=inet_addr("127.0.0.1");
cli.sin_port=htons(5000);
connect(ls,(struct
sockaddr*)&cli,sizeof(cli));
recv(ls,buf1,1000,0);
printf("Old Story is : %s\n",buf1);
puts("Enter Text : ");
fgets(buf,1000,stdin);
printf("Message to server : %s\n",buf);
send(ls,buf,1000,0);
recv(ls,buf1,1000,0);
printf("Current Story is : %s",buf1);
close(ls);
return 0;
}


// emcc -o client.html client.c -s WASM=1 -O3 -s EXPORTED_FUNCTIONS="['_socket','_bind','_connect','_send','_recv','_main']"