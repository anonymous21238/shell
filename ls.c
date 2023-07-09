#include<stdio.h>
#include<string.h>
#include<dirent.h>




int main(int argc, char *argv[])
{
    
    DIR* dir = opendir(".");
    if(dir ==NULL){
        printf("error");
        return 0;
    } 

    else if(argc == 1){
        // printf("hi");
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

    else if(strcmp(argv[1],"-1")==0 && argc ==2){
        struct dirent* entity;
        entity = readdir(dir);
        while(entity !=NULL){
            if(strcmp(entity->d_name,".")!=0 && strcmp(entity->d_name,"..")!=0   ){
                printf("%s\n",entity->d_name);
                entity = readdir(dir);
            }
            else{
                entity = readdir(dir);
            }
        }
        closedir(dir);
    }

    

    else if(strcmp(argv[1],"-a")==0 && argc ==2){
        struct dirent* entity;
        entity = readdir(dir);
        while(entity !=NULL){
            printf("%s ",entity->d_name);
            entity = readdir(dir);
        }
        closedir(dir);
    }

    else if(((strcmp(argv[1],"-a")==0 && strcmp(argv[2],"-1")==0) || (strcmp(argv[2],"-a")==0 && strcmp(argv[1],"-1")==0)) && argc ==3 ){
        struct dirent* entity;
        entity = readdir(dir);
        while(entity !=NULL){
            printf("%s\n",entity->d_name);
            entity = readdir(dir);
        }
        closedir(dir);
    }

    else if(argv[1][0]=='-'){
        printf("This feature is not yet implimented by the programmer\n");
    }




    else if(argc>=3 ){
            printf("only 1 or 2 arguments can be implimented\n");
        }


    
    return 0;
}
