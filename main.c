#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include<windows.h>
#define back printf("\n\n")
#define spac printf("\t")

int main()
{
    while(1){

    int i,j;
    char h,answer[10];
    int up=72,down=80,left=75,right=77,lvl,lvlchoise;
    int direction,last_direc=right;
    int x,y,x1,y1,scor=0,siz=3,x2,y2,x3,y3;
    int body[99999][2];
    char filde[11][51];

    body[1][0]=5;
    body[1][1]=24;
    body[2][0]=5;
    body[2][1]=23;
    body[3][0]=5;
    body[3][1]=22;

    /*background*/{

    for(int y=0;y<11;y++){
        for(int x=0;x<51;x++){
            if((x==0 || x==50)||(y==0 || y==10)){
                filde[y][x]='!';
            }else{
                filde[y][x]=' ';
            }
        }
    }
    filde[5][25]='>';
    for(int lol=0;lol<2;lol++){
        loopz:
        x3=1+ rand()%49;
        y3=1+ rand()%9;
        for(int i=0;i<siz;i++){
            if(x3==body[i][1] || y3==body[i][0]){
                goto loopz;
            }
            break;
        }
        filde[y3][x3]='O';
    }
    filde[5][24]='*';
    filde[5][23]='*';
    filde[5][22]='*';
    }

    printf("\n\n\t\tSNAKE GAME\n\nWelcome to my first game \"snake\" rules are simple one life and make high score \nif u want to play entre 'yes' if u want to exite entre 'exite'.\n\n-YOUR answer:");
    read:
    scanf("%s",&answer);
    for(int i=0;i<strlen(answer);i++){
        answer[i]=toupper(answer[i]);
    }
    if(answer[0]=='Y' && answer[1]=='E' && answer[2]=='S'){
        goto play;
    }else if(answer[0]=='E' && answer[1]=='X' && answer[2]=='I' && answer[3]=='T' && answer[4]=='E'){
        goto exite2;
    }else{
        printf("Ereur entre yes or exite\n");
        goto read;
    }

    play:
    do{
        system("cls");
        printf("\n\n\n\t\t  Entre your choise: \n\n\t\t 0 : |  Level baby  |\n\t\t 1 : |  Level easy  |\n\t\t 2 : |  Level moyen |\n\t\t 3 : |  Level hard  |\n\t\t 4 : |  Level hell  |\n\n\t\tChoise(number)  :  ");
        scanf("%d",&lvlchoise);
        if(lvlchoise<0 || lvlchoise>4){
            printf("\n\tEreur entre one of 4 choise ");
            usleep(1500000);
        }
    }while(lvlchoise<0 || lvlchoise>4);
    switch (lvlchoise){
        case(0):
            lvl=450;
        break;
        case(1):
            lvl=200;
        break;
        case(2):
            lvl=120;
        break;
        case(3):
            lvl=70;
        break;
        case(4):
            lvl=20;
        break;

    }

    system("cls");
    printf("\n\n\n\t\t\tLOADING GAME\n\t\t");
    for(int i=0;i<29;i++){
        printf("|");
        usleep(30000);
    }
    printf("\n\n\n\ngame is ready...");
    sleep(1);
    system("cls");

    while(1){
        back;
        printf("\tSCORE : %d\n",scor);
        for(int y=0;y<11;y++){
            spac;
            for(int x=0;x<51;x++){
                printf("%c",filde[y][x]);
            }
            printf("\n");
        }
        direction=last_direc;




        //////////////////////////////////////////////
        int time_crono=lvl;
        while(time_crono>0) {
            if(kbhit()) {
                direction=getch();
                break;
            }
            usleep(1);
            time_crono--;
        }
        /////////////////////////////////////////////




        for(int i=0;i<11;i++){
            for(int j=0;j<51;j++){
                if(filde[i][j]=='>' || filde[i][j]=='<' || filde[i][j]=='V' || filde[i][j]=='^'){
                    y=i;
                    x=j;
                }
            }
        }
        body[0][0]=y;
        body[0][1]=x;
        if(direction==right && last_direc!=left)filde[y][x]='>';
        else if(direction==left && last_direc!=right)filde[y][x]='<';
        else if(direction==up && last_direc!=down)filde[y][x]='^';
        else if(direction==down && last_direc!=up)filde[y][x]='V';
        if(direction==right){
            if(last_direc==direction || last_direc!=left){
                if(filde[y][x+1]!='!' && filde[y][x+1]!='O'){
                        if(filde[y][x+1]=='*')goto exite;
                        h=filde[y][x+1];
                        filde[y][x+1]=filde[y][x];
                        filde[y][x]=h;
                        y2=body[siz][0];
                        x2=body[siz][1];
                        for(i=siz;i>0;i--){
                            for(j=0;j<2;j++){
                                body[i][j]=body[i-1][j];
                            }
                            y1=body[i][0];
                            x1=body[i][1];
                            filde[y1][x1]='*';
                        }
                        filde[y2][x2]=' ';
                }else if(filde[y][x+1]=='O'){
                        h=filde[y][x+1];
                        h='*';
                        filde[y][x+1]=filde[y][x];
                        filde[y][x]=h;
                        Beep(500,100);
                        scor+=2;
                        siz++;
                        for(int i=siz;i>0;i--){
                            for(int j=0;j<2;j++){
                                body[i][j]=body[i-1][j];
                            }
                        }
                        ////////////////////////////////////////
                        loop1:
                        x3=2+ rand()%46;
                        y3=2+ rand()%7;
                        for(int i=0;i>=0;i++){
                            if(filde[y3][x3]=='*' || filde[i][j]=='>' || filde[i][j]=='<' || filde[i][j]=='V' || filde[i][j]=='^'|| filde[y3][x3]=='O'){
                                goto loop1;
                            }
                            break;
                        }
                        filde[y3][x3]='O';


                }else{
                    goto exite;
                }
                last_direc=direction;
            }else{
                Beep(2000,150);
            }
        }
        if(direction==left){
            if(last_direc==direction || last_direc!=right){
                if(filde[y][x-1]!='!' && filde[y][x-1]!='O'){
                        if(filde[y][x-1]=='*')goto exite;
                        h=filde[y][x-1];
                        filde[y][x-1]=filde[y][x];
                        filde[y][x]=h;
                        y2=body[siz][0];
                        x2=body[siz][1];
                        for(i=siz;i>0;i--){
                            for(j=0;j<2;j++){
                                body[i][j]=body[i-1][j];
                            }
                            y1=body[i][0];
                            x1=body[i][1];
                            filde[y1][x1]='*';
                        }
                        filde[y2][x2]=' ';
                }else if(filde[y][x-1]=='O'){
                        h=filde[y][x-1];
                        h='*';
                        filde[y][x-1]=filde[y][x];
                        filde[y][x]=h;
                        Beep(500,100);
                        scor+=2;
                        siz++;
                        for(int i=siz;i>0;i--){
                            for(int j=0;j<2;j++){
                                body[i][j]=body[i-1][j];
                            }
                        }
                        //////////////////////////////////////////
                        loop2:
                        x3=2+ rand()%46;
                        y3=2+ rand()%7;
                        for(int i=0;i>=0;i++){
                            if(filde[y3][x3]=='*' || filde[i][j]=='>' || filde[i][j]=='<' || filde[i][j]=='V' || filde[i][j]=='^' || filde[y3][x3]=='O'){
                                goto loop2;
                            }
                            break;
                        }
                        filde[y3][x3]='O';


                }else{
                    goto exite;
                }
                last_direc=direction;
            }else{
                Beep(2000,150);
            }
        }
        if(direction==up){
            if(last_direc==direction || last_direc!=down){
                if(filde[y-1][x]!='!' && filde[y-1][x]!='O'){
                        if(filde[y-1][x]=='*')goto exite;
                        h=filde[y-1][x];
                        filde[y-1][x]=filde[y][x];
                        filde[y][x]=h;
                        y2=body[siz][0];
                        x2=body[siz][1];
                        for(i=siz;i>0;i--){
                            for(j=0;j<2;j++){
                                body[i][j]=body[i-1][j];
                            }
                            y1=body[i][0];
                            x1=body[i][1];
                            filde[y1][x1]='*';
                        }
                        filde[y2][x2]=' ';
                }else if(filde[y-1][x]=='O'){
                        h=filde[y-1][x];
                        h='*';
                        filde[y-1][x]=filde[y][x];
                        filde[y][x]=h;
                        Beep(500,100);
                        scor+=2;
                        siz++;
                        for(int i=siz;i>0;i--){
                            for(int j=0;j<2;j++){
                                body[i][j]=body[i-1][j];
                            }
                        }
                        ////////////////////////////////////////////////
                        loop3:
                        x3=2+ rand()%46;
                        y3=2+ rand()%7;
                        for(int i=0;i>=0;i++){
                            if(filde[y3][x3]=='*' || filde[i][j]=='>' || filde[i][j]=='<' || filde[i][j]=='V' || filde[i][j]=='^' || filde[y3][x3]=='O'){
                                goto loop3;
                            }
                            break;
                        }
                        filde[y3][x3]='O';

                }else{
                    goto exite;
                }
                last_direc=direction;
            }else{
                Beep(2000,150);
            }
        }
        if(direction==down){
            if(last_direc==direction || last_direc!=up){
                if(filde[y+1][x]!='!' && filde[y+1][x]!='O'){
                        if(filde[y+1][x]=='*')goto exite;
                        h=filde[y+1][x];
                        filde[y+1][x]=filde[y][x];
                        filde[y][x]=h;
                        y2=body[siz][0];
                        x2=body[siz][1];
                        for(i=siz;i>0;i--){
                            for(j=0;j<2;j++){
                                body[i][j]=body[i-1][j];
                            }
                            y1=body[i][0];
                            x1=body[i][1];
                            filde[y1][x1]='*';
                        }
                        filde[y2][x2]=' ';
                }else if(filde[y+1][x]=='O'){
                        h=filde[y+1][x];
                        h='*';
                        filde[y+1][x]=filde[y][x];
                        filde[y][x]=h;
                        Beep(500,100);
                        scor+=2;
                        siz++;
                        for(int i=siz;i>0;i--){
                            for(int j=0;j<2;j++){
                                body[i][j]=body[i-1][j];
                            }
                        }
                        //////////////////////////////////////
                        loop4:
                        x3=2+ rand()%46;
                        y3=2+ rand()%7;
                        for(int i=0;i>=0;i++){
                            if(filde[y3][x3]=='*' || filde[i][j]=='>' || filde[i][j]=='<' || filde[i][j]=='V' || filde[i][j]=='^' || filde[y3][x3]=='O'){
                                goto loop4;
                            }
                            break;
                        }
                        filde[y3][x3]='O';


                }else{
                    goto exite;
                }
                last_direc=direction;
            }else{
                Beep(2000,150);
            }
        }
        if(siz==323){
            system("cls");
            printf("\n\n\n\n\n\n\t\t   YOU BEAT THE GAME\n\t\t\t!!GAME OVER!!\n\n\n\n\n\n");
            goto exite2;
        }
        system("cls");
    }

    exite:
    Beep(3000,50);
    Beep(2000,100);
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t   YOU DIE\n\t\t\t!!GAME OVER!!\n\n\n\n\n\n");
    switch (lvlchoise){
        case(0):
            printf("\n\n\n\t\t\tYOUR fucking NOOB");
        break;
        case(1):
            if(scor>=100)
                printf("\n\n\n\t\t\tNot bad but u still NOOB");
            else
                printf("\n\t\tLevel easy and u get less than 100 are u serious");
        break;
        case(2):
            if(scor>=150)
                printf("\n\n\n\t\t\tCool good luck");
            else
                printf("\n\t\tWell play ,goodd next time");
        break;
        case(3):
            if(scor>=150)
                printf("\n\n\n\t\t\tNice you are PRO");
            else
                printf("\n\t\tWell play ,good next time");
        break;
        case(4):
            if(scor>=150)
            printf("\n\n\n\t\t\tAre u even a human");
            else
                printf("\n\t\tWell play ,good next time");
        break;

    }
    sleep(2);
    system("cls");
    }
    exite2:
    printf("\n\n\nklick any key to exite.....");
    sleep(2);
    getch();
    return 0;

}
