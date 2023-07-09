#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
	int temp;
	//printf("%c",argv[1][0]);
    if(argc == 1){
        printf("No file name provided\n");
    }

    

	else if(strcmp(argv[1],"-i")==0){
		printf("Are you sure you want to delete: ");
		char ch;
		scanf("%c",&ch);
        if(ch == 'y' || ch == 'Y'){
            for(int i=2;i<argc;i++){
                temp = remove(argv[i]);
                if(temp!=0){
                    printf("file does not exists\n");
                    break;
                }
            }
        }
		else{
			printf("you have chosen not to delete\n");
		}
	}

    else if(argv[1][0]=='~' && argc == 2){
        char *p = argv[1];
        p++;
        temp = remove(p);
        if(temp!=0){
            printf("file does not exists\n");
        }
            
	}
    
	else if(argv[1][0]=='/' && argc == 2){
		char *p = argv[1];
		p++;
		p++;
		p++;
		p++;
		p++;
		temp = remove(p);
		if(temp !=0){
			printf("file does not found\n");
		}
	}

    else if((argv[1][0]=='~' || argv[1][0]=='/') && argc > 2){
        printf("please enter only one path\n");
	}

    else if(argv[1][0]=='-'){
        printf("This fuction is not yet implimented by the programmer yet\n");
    }


	else{
        for(int i=1;i<argc;i++){
		printf("abe yaar");
                temp = remove(argv[i]);
                if(temp!=0){
                    printf("file does not exists\n");
                    break;
                }
            }
	}

	
	return 0;
}
