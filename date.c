#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main(int argc, char *argv[]){
   //char *argv[32]={"date","\"+%%T\""};
	//printf("%s",argv[1]);
    time_t t;
    if(argv[1]==NULL ){
        
	    time(&t);
        
	    printf("%s\n",ctime(&t));
	    
    }

	else if(strcmp(argv[1],"\"+%Y\"")==0  || strcmp(argv[1],"+%Y")==0 ){
        time(&t);
        char ti[256];
        strcpy(ti,ctime(&t));
        char *array[16];
        int cnt;
        cnt = 0;
        char *p = ti;
        while(*p != '\0')
        {
            if(*p  == ' ')
            {
                *p = '\0';
                p++;
                continue;
            }
            array[cnt++] = p;
            while(*p != '\0' && *p != ' ' ){
                p++;
            }
                
        }
        array[cnt] = NULL;
        printf("%s",array[4]);
    }

    else if(strcmp(argv[1],"\"+%a\"")==0 || strcmp(argv[1],"+%a")==0 ){
        time(&t);
        char ti[256];
        strcpy(ti,ctime(&t));
        char *array[16];
        int cnt;
        cnt = 0;
        char *p = ti;
        while(*p != '\0')
        {
            if(*p  == ' ')
            {
                *p = '\0';
                p++;
                continue;
            }
            array[cnt++] = p;
            while(*p != '\0' && *p != ' ' ){
                p++;
            }
                
        }
        array[cnt] = NULL;
        printf("%s",array[0]);
	printf("\n");
    }

    else if(strcmp(argv[1],"\"+%T\"")==0  || strcmp(argv[1],"+%T")==0){
        time(&t);
        char ti[256];
        strcpy(ti,ctime(&t));
        char *array[16];
        int cnt;
        cnt = 0;
        char *p = ti;
        while(*p != '\0')
        {
            if(*p  == ' ')
            {
                *p = '\0';
                p++;
                continue;
            }
            array[cnt++] = p;
            while(*p != '\0' && *p != ' ' ){
                p++;
            }
                
        }
        array[cnt] = NULL;
        printf("%s",array[3]);
	printf("\n");
    }
   else if(argc>2){
	printf("you have entered %d function at a time only one function is supported at a time\n",argc-1);
	}
	else{
	printf("sorry this function is not yet implimented by the programmer\n");
	}
	 
   //printf("%d",argc);	
	
    return 0;
}
