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

scanf("%s", command);
if(command == NULL){
break;
}

command[strcspn(command, "\n")] = 0;

if (strcmp(command, "myclear") == 0){
system("clear");
} else if (strcmp(command, "mydir") == 0){

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
