#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int main() {
char command[1024];

while(1){

printf("==> ");
fflush(stdout);

if(fgets(command, sizeof(command), stdin) == NULL){
break;
}

command[strcspn(command, "\n")] = 0;

if (strcmp(command, "myclear") == 0){
system("clear");
} else if (strcmp(command, "mydir") == 0){
char *dir = command + 6;
if(*dir == '\0'){
dir = ".";
}

char dir_cmd[1024];
snprintf(dir_cmd, sizeof(dir_cmd), "ls -al %s", dir);
system(dir_cmd);
} else if (strcmp(command, "myenviron") == 0){
char **env = environ;
while(*env){
printf("%s\n", *env++);
}
} else if(strcmp(command, "myquit") == 0){
exit(0);
} else {
system(command);
}

}

return 0;
}
