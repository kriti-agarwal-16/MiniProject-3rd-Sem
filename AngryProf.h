#include<stdio.h>
#include<stdlib.h>

void classOnOff(char argv[]){

    int i,j,x,T,N,P,present,w;
    FILE *fp,*fp1;
    char test[10000],output1[10];

    printf("Press 1 for output on screen & press 2 for output on file ");
    scanf("%d",&w);

    if(w!=1 && w!=2){
        printf("..Invalid Output Location..\n");
        return;
    }

    if(w==2){
        printf("Enter name of output file: ");
        scanf("%s",output1);
    }

    fp=fopen(argv,"r");

    if(fp==NULL){
        printf("..Input file does not exist..");
        return;
    }

    if(w==2){
        fp1=fopen(output1,"w");
    }
    if((fscanf(fp,"%s",test))==EOF){
        printf("Input file is empty\n");
        return;
    }
    T=atoi(test);
    if(T>0 && T <10000)
    {
        for(i=0;i<T;i++){
            P=0;
            N=0;
            present=0;
            fscanf(fp,"%d%d",&N,&P);

            if(N<P){
                if(w==2){
                        fprintf(fp1,"Total students are less than the required attendance\n");
                        break;
                }
                if(w==1){
                        printf("Total students are less than the required attendance\n");
                        break;
                }
            }

            if(N!=0 && P!=0 )
            {
                for(j=0;j<N;j++){
                    fscanf(fp,"%d",&x);
                    if(x<=0){
                        present++;
                    }
                }
                if(present>=P){
                    if(w==2)
                        fprintf(fp1,"ON\n");
                    if(w==1)
                        printf("ON\n");
                }
                else{
                    if(w==2)
                        fprintf(fp1,"OFF\n");
                    if(w==1)
                        printf("OFF\n");
                }
            }
            else{
                if(w==2)
                    fprintf(fp1,"No valid cases available\n");
                if(w==1)
                    printf("No valid case available");
                break;
            }
        }
    }
    else{
        if(w==2)
            fprintf(fp1,"Invalid number of Test Case\n");
        if(w==1)
            printf("Invalid number of Test Case\n");
    }
    fclose(fp);
    if(w==2)
        fclose(fp1);
}
