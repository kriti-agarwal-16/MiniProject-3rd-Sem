#include "AngryProf.h"
#include "PrimeGame.h"

int main(int argc,char *argv[]){
    int ch;
        if(argc<3){
            printf("\t..Too few arguments on command line..\n");
            return 0;
        }
        printf("...........MENU...........\n");
        printf("1. Prof Gussadhar's Class\n");
        printf("2. Sub-range Game\n");
        printf("3. Exit\n");
        printf("Enter your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : classOnOff(argv[1]);
                    break;
            case 2 : subDigit(argv[2]);
                    break;
            case 3 : break;

            default:printf("..You have entered a invalid choice..\n");
                    return 0;

        }


    return 0;
}
