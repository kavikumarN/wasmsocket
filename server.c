#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <emscripten.h>
#include <netinet/in.h>
#include <string.h>
int main()
{
int ls,cs,len,i;
char buf[1000],buf1[1000];

struct sockaddr_in serv,cli;
ls=socket(AF_INET,SOCK_STREAM,0);

serv.sin_family=AF_INET;
serv.sin_addr.s_addr=INADDR_ANY;
serv.sin_port=htons(5000);
bind(ls,(struct sockaddr*)&serv,sizeof(serv));
listen(ls,5);
for(int i=0;i<300;i++)
{
len=sizeof(cli);
cs=accept(ls,(struct sockaddr*)&cli,&len);
send(cs,buf1,1000,0);
recv(cs,buf,1000,0);
printf("Message from client : %s\n",buf);
strcpy(buf1,buf);
send(cs,buf1,1000,0);
}
close(cs);
return 0;
}

// emcc -o server.html server.c -s WASM=1 -O3 -s EXPORTED_FUNCTIONS="['_socket','_bind','_listen','_accept','_send','_inet_addr','_recv','_main']"