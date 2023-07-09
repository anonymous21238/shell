#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<signal.h>
#include<pthread.h>
#include<dirent.h>

int cnt;
void format(char input[],char* array[])
{
    cnt = 0;
    char *p = input;
    while(*p != '\0')
    {
        if(*p  == ' ')
        {
            *p = '\0';
            p++;
            continue;
        }
        array[cnt++] = p;
        while(*p != '\0' && *p != ' ' )
            p++;
    }

        array[cnt] = NULL;
    
    
}

void backslashn(char input[]){
    char *t = input;
    while(*t != '\0'){
        if(*t == '\n'){
            *t = '\0';
        }
        t++;
    }
}

void echoo(char input[], char* array[]){
    if(strcmp(array[1],"-n")==0){
        for(int i=2;i<16;i++){
            if(array[i] != NULL){
                printf("%s ",array[i]);
            }
            else{
                break;
            }
            
        }
    }

    else if(strcmp(array[1],"*")==0){
        DIR* dir = opendir(".");
        if(dir ==NULL){
            printf("error\n");
          
        }
        struct dirent* entity;
        entity = readdir(dir);
        while(entity !=NULL){
            if(strcmp(entity->d_name,".")!=0 && strcmp(entity->d_name,"..")!=0 ){
                printf("%s ",entity->d_name);
                entity = readdir(dir);
            }
            else{
                entity = readdir(dir);
            }
        }
	printf("\n");
        closedir(dir);

    }
    
    else{
        for(int i=1;i<16;i++){
            if(array[i] != NULL){
                printf("%s ",array[i]);
            }
            else{
                break;
            }
        }
        printf("\n");
    }
}


void pwdd(char final[], char* array[]){
    char location[256];
    if(strcmp(final,"pwd")==0){
        getcwd(location,256);
        printf("%s\n",location);
        return;
    }
    
    else if(strcmp(array[1],"-L")==0 || strcmp(array[1],"-P")==0){
    getcwd(location,256);
    printf("%s\n",location);
    }
    else{
        printf("Error\n");
    }

}

void cdd(char input[], char* pth){
    char oldlocation[256];
    int ret;
	if (pth[0] == '.') {
		getcwd(oldlocation, sizeof(oldlocation));
		strcat(oldlocation,"/");
		strcat(oldlocation,pth);
		ret = chdir(oldlocation);	
	}
	else if (pth[0] == '~') {
		pth++;
		char *oldlocation = getenv("HOME");
		strcat(oldlocation, pth);
		ret = chdir(oldlocation);
	}
	else {
		ret = chdir(pth);
	}
	if (ret == -1) {
		printf("Invalid Path\n");
	}
	else {
		char newloc[256];
		getcwd(newloc, sizeof(newloc));
		printf("%s\n", newloc);
	}
}



int main()
{
    while(1){
    char input[256];
    char final[256];
    char *array[32];
    printf("customshell-->>  ");
    fgets(input,256,stdin);
    strcpy(final,input);
    backslashn(input);
    backslashn(final);
    if(strcmp(input,"exit")==0){
        return 0;
    }
    else if(strcmp(input,"")==0){
        continue;
    }
    format(input,array);
    if(strcmp(array[0],"echo")==0){
        echoo(final,array);
	    continue;
        
    }
    else if(strcmp(array[0],"pwd")==0){
        pwdd(final,array);
	    continue;
    }
    else if(strcmp(array[0],"cd")==0){
	if(array[2] != NULL){
		printf("You have provided two paths");
		continue;
	}
        cdd(final,array[1]);
	    continue;
    }

    




    if(strcmp(array[0],"&t")==0){
        if(strcmp(array[1],"date")==0){
        	char str[256] = "/home/Assignment2/date";
		for(int i=2;i<32;i++){
			if(array[i] !=NULL){
				strcat(str," ");
				strcat(str,array[i]);

			}
			else{
				break;
			}

		}
            pthread_t thread;
            pthread_create(&thread, NULL,(void*)(*system),(void*)str);
            pthread_join(thread,NULL);
        }

        else if(strcmp(array[1],"cat")==0){
        	char str[256] = "/home/Assignment2/cat";
		for(int i=2;i<32;i++){
			if(array[i] !=NULL){
				strcat(str," ");
				strcat(str,array[i]);

			}
			else{
				break;
			}

		}
            pthread_t thread;
            pthread_create(&thread, NULL,(void*)(*system),(void*)str);
            pthread_join(thread,NULL);
        }

        else if(strcmp(array[1],"mkdir")==0){
        	char str[256] = "/home/Assignment2/mkdir";
		for(int i=2;i<32;i++){
			if(array[i] !=NULL){
				strcat(str," ");
				strcat(str,array[i]);

			}
			else{
				break;
			}

		}
            pthread_t thread;
            pthread_create(&thread, NULL,(void*)(*system),(void*)str);
            pthread_join(thread,NULL);
        }

        else if(strcmp(array[1],"rm")==0){
        	char str[256] = "/home/Assignment2/rm";
		for(int i=2;i<32;i++){
			if(array[i] !=NULL){
				strcat(str," ");
				strcat(str,array[i]);

			}
			else{
				break;
			}

		}
            pthread_t thread;
            pthread_create(&thread, NULL,(void*)(*system),(void*)str);
            pthread_join(thread,NULL);
        }

        else if(strcmp(array[1],"ls")==0){
        	char str[256] = "/home/Assignment2/ls";
		for(int i=2;i<32;i++){
			if(array[i] !=NULL){
				strcat(str," ");
				strcat(str,array[i]);

			}
			else{
				break;
			}

		}
            pthread_t thread;
            pthread_create(&thread, NULL,(void*)(*system),(void*)str);
            pthread_join(thread,NULL);
        }

        else{
            printf("No such command exists yet");
        }

    }





    



    else{
        pid_t pid;
        if(strcmp(array[0],"mkdir")==0){
            pid = fork();
            if(pid == 0){
                execv("/home/Assignment2/mkdir", array);
            }
            else if(pid==-1) {
                printf("Fork Error!");
            }
            else{   
                waitpid(pid, NULL, 0);
            }
            continue;
        }
        else if(strcmp(array[0],"cat")==0){
            pid = fork();
            if(pid == 0){
                execv("/home/Assignment2/cat", array);
            }
            else if(pid==-1) {
                printf("Fork Error!");
            }
            else{   
                waitpid(pid, NULL, 0);
            }
            continue;
        }
        else if(strcmp(array[0],"date")==0){
            pid = fork();
            if(pid == 0){
                execv("/home/Assignment2/date", array);
            }
            else if(pid==-1) {
                printf("Fork Error!");
            }
            else{   
                waitpid(pid, NULL, 0);
            }
            continue;
        }
        else if(strcmp(array[0],"rm")==0){
            pid = fork();
            if(pid == 0){
                execv("/home/Assignment2/rm", array);
            }
            else if(pid==-1) {
                printf("Fork Error!");
            }
            else{   
                waitpid(pid, NULL, 0);
            }
            continue;
        }
        else if(strcmp(array[0],"ls")==0){
            pid = fork();
            if(pid == 0){
                execv("/home/Assignment2/ls", array);
            }
            else if(pid==-1) {
                printf("Fork Error!");
            }
            else{   
                waitpid(pid, NULL, 0);
            }
            continue;
        }
        else{
            printf("No such command exists yet");
        }
	
    }
       
	




    
    }
    return 0;
}
