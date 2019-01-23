#include <string.h>
#include <emscripten.h>
#include <emscripten/bind.h> 

using namespace emscripten;
char* EMSCRIPTEN_KEEPALIVE viewc(char* email);
char*  EMSCRIPTEN_KEEPALIVE entryc(char* name, int sid, char* email, int mark1, int mark2, int mark3 );
//emcc -s NO_EXIT_RUNTIME=1 -s EXPORTED_FUNCTIONS="['_world','_viewc','_entryc']" abc.c -o abc.js
 struct student
 {
 	int studentid;
 	char name[14];
 	char email[14];
 	int m1,m2,m3;
 	float avg;
 } s[10];

 int pos = 0;
 int count = 0;

 //char a[14];
// char* world(char* uname, char* pwd) {
// 	char user[10][2];
// 	strcpy(user[0][0],uname);
// 	strcpy(user[0][1],pwd);
// 	int i,j;
// 	for(i=0;i<10;i++)
// 	{
// 		for(j=0;j<2;j++)
// 		{
// 			if(user[i][j] == user[0][0])
// 			{
// 			if(user[i][j] == user[0][1])
// 				//return user[i][0];
// 				printf("login works");
// 			}

// 		} 
		
// 	} return user[i][0];
// } 


char* EMSCRIPTEN_KEEPALIVE viewc(char* email) {

	char temp[] = "Invalid";
	for(count=0;count<50;count++)
	{
		
		if(strcmp(s[count].email,email)==0)
			return (s[count].name);
		else 
			return "temp";
		
	}

	return "err";
}



char*  EMSCRIPTEN_KEEPALIVE entryc(char* name, int sid, char* email, int mark1, int mark2, int mark3 ) {

	strcpy(s[pos].name,name);
	s[pos].studentid = sid;
	strcpy(s[pos].email,email);
	s[pos].m1 = mark1;
	s[pos].m2 = mark2;
	s[pos].m3 = mark3;
	s[pos].avg = (mark3+mark2+mark1)/3;
	pos++;
	return (s[pos-1].email);
	
}
int main() {
  
  //emscripten_exit_with_live_runtime();

  return 0;
}