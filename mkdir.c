#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>




int main(int argc, char* argv[]){
    if(argc == 1){
        printf("No file name provided\n");
    }

    else if(strcmp(argv[1],"-v")==0 || strcmp(argv[1],"-verbose")==0){
        int temp;
        for(int i=2;i<argc;i++){
            temp = mkdir(argv[i], 0777);
	        if(temp != 0){
		        printf("Directory already exists\n");
	        }
		else{
	            printf("mkdir: created directory %s",argv[i]);		
		}
        }
    }

    else if(strcmp(argv[1],"-p")==0){
        int temp;
        for(int i=2;i<argc;i++){
            temp = mkdir(argv[i], 0777);
        }
    }


    else if(strcmp(argv[1],"--version")==0){
        printf("version 1.0 \nWritten by Aryesh Shakya.\n");
    }

    else if(argv[1][0]=='-'){
        printf("This fuction is not yet implimented by the programmer yet\n");
    }

    else{
        int temp;
        for(int i=1;i<argc;i++){
            temp = mkdir(argv[i], 0777);
            //printf("mkdir: created directory %s",argv[i]);
	        if(temp != 0){
		        printf("Directory already exists\n");
	        }
        }
    }

	
	return 0;
}
