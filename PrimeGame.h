void subDigit(char []);
int prime(int,int);

void subDigit(char argv[]){

    int i,j,p,n,T,X,Y,w;
    float prob;
    char test[10000],range1[1000000],range2[1000000],output2[10];
    FILE *fp,*fp1;

    printf("Press 1 for output on screen & press 2 for output on file ");
    scanf("%d",&w);

    if(w!=1 && w!=2){
        printf("..Invalid Output Location..\n");
        return;
    }

    if(w==2){
        printf("Enter name of Output file: ");
        scanf("%s",output2);
    }

    fp=fopen(argv,"r");

    if(fp==NULL){
        printf("..Input file does not exist..");
        return;
    }

    if(w==2)
        fp1=fopen(output2,"w");
    if((fscanf(fp,"%s",test))==EOF){
        printf("Input File is empty");
        return;
    }

    T=atoi(test);
    if(T>0 && T<10000){
        for(i=0;i<T;i++){
            range1[0]='a';
            range2[0]='a';
            fscanf(fp,"%s%s",range1,range2);
            X=atoi(range1);
            Y=atoi(range2);

            if(X>Y){
                if(w==2){
                    fprintf(fp1,"Upper limit is lower than lower limit.\n");
                    return;
                }
                if(w==1){
                    printf("Upper limit is lower than lower limit.\n");
                    return;
                }
            }

            if(X>0 && Y>0){
                if(X==1 && Y==1)
                    p=0;
                else if(X==1 && Y!=1)
                    p=prime(X+1,Y);
                else
                    p=prime(X,Y);
                n=Y-X+1;
                prob=(float)p/n;
                if(w==2)
                    fprintf(fp1,"%f\n",prob);
                if(w==1)
                    printf("%f\n",prob);
            }
            else{
                if(w==2)
                    fprintf(fp1,"Valid range not available\n");
                if(w==1)
                    printf("Valid range not available\n");
                break;
            }
        }
    }
    else
    {
        if(w==2)
            fprintf(fp1,"Invalid number of Test Case\n");
        if(w==1)
            printf("Invalid number of Test Case\n");
    }
    fclose(fp);
    if(w==2)
        fclose(fp1);
}
int prime(int x,int y){
    int i,j,c=0,f;
    for(i=x;i<=y;i++){
        f=0;
        for(j=2;j<i;j++){
            if(i%j==0){
                f=1;
                break;
            }
        }
        if(f==0)
            c++;
    }
    return c;
}
