#include<stdio.h>
#include<string.h>


int main(int argc, char const *argv[]){
	FILE* ptr;
    if(argc<2){
        printf("NO file name provided");
        return 0;
    }

    if(argv[2]==NULL){
        ptr = fopen(argv[1],"r");
        char ch = fgetc(ptr);
		while(ch != EOF){
			printf("%c",ch);
			ch = fgetc(ptr);
		}
		
	//printf("%s",ptr);
	if(ptr == NULL){
		printf("File not found\n");
	}
    }

    else if(strcmp(argv[1],"-n")==0 && argc == 3){
        ptr = fopen(argv[2],"r");
        char l[512];
        int l_count = 1;
        while(fgets(l,sizeof(l),ptr)){
            printf("    %d",l_count);
            printf(" %s",l);
            l_count++;
        }
	if(ptr == NULL){
		printf("File not found\n");
	}
    }

    else if(strcmp(argv[1],"-E")==0 && argc == 3){
        ptr = fopen(argv[2],"r");
        char l[512];      
        while(fgets(l,sizeof(l),ptr)){
            char *c = l;
            int k=0;
            while(*c != '\0' ){
                if(*c == '\n' || *c == EOF){
                    *c = '$';
                    k=1;
                    break;
                }
                c++;
            }
            if(k==1){
                printf("%s\n",l);
            }
            else{
                printf("%s$",l);
            }   
        }
	if(ptr == NULL){
		printf("File not found\n");
	}
        
    }

    else if(((strcmp(argv[1],"-n")==0) && strcmp(argv[2],"-E")==0) || ((strcmp(argv[1],"-E")==0) && strcmp(argv[2],"-n")==0) && argc == 4){
        ptr = fopen(argv[3],"r");
        char l[512];
        int l_count = 1;
        while(fgets(l,sizeof(l),ptr)){
            printf("    %d",l_count);
            
            char *c = l;
            int k=0;
            while(*c != '\0' ){
                if(*c == '\n' || *c == EOF){
                    *c = '$';
                    k=1;
                    break;
                }
                c++;
            }
            if(k==1){
                printf(" %s\n",l);
            }
            else{
                printf(" %s$",l);
            } 
            l_count++;
        }
	if(ptr == NULL){
		printf("File not found\n");
	}
    }
	
	else if(argc > 3){
		printf("you have given %d fuctions to perform but currently only one or two function at a time is available\n",argc-1);
	}


	else{
        printf("This fuction is not yet available/n");
	}
	return 0;
}
