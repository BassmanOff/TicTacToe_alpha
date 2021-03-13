//
//  main.c
//  TicTacToe
//
//  Created by BassmanOff on 13.03.2021.
//

#include <stdio.h>
#include <stdlib.h>

unsigned char net[3][3];      // Сетка 3x3

unsigned char pace;           // Ход игрока

void XO(char X, char Y){
    if (net[X][Y] == 0) {
        printf(" ");
    } else if (net[X][Y] == 1) {
        printf("X");
    } else if (net[X][Y] == 2) {
        printf("O");
    }
}

char updateGameScreen(void){
    system("clear");
    
    printf("_______");
    
    printf("\n|");
    XO(0, 0);
    printf("|");
    XO(1, 0);
    printf("|");
    XO(2, 0);
    printf("|");
    
    printf("\n|");
    XO(0, 1);
    printf("|");
    XO(1, 1);
    printf("|");
    XO(2, 1);
    printf("|");
    
    printf("\n|");
    XO(0, 2);
    printf("|");
    XO(1, 2);
    printf("|");
    XO(2, 2);
    printf("|\n");
    printf("-------");
    return 0;
}

_Bool winTest(void){
    for (char i = 0; i<3; i++) {
        if (net[0][i]==net[1][i] && net[0][i]==net[2][i] && net[0][i]!=0) {
            return 1;
        }
    }
    
    for (char i = 0; i<3; i++) {
        if (net[i][0]==net[i][1] && net[i][0]==net[i][2] && net[i][0]!=0) {
            return 1;
        }
    }
    
    if (net[0][0]==net[1][1] && net[0][0]==net[2][2] && net[0][0]!=0) {
        return 1;
    }
    
    if (net[2][0]==net[1][1] && net[2][0]==net[0][2] && net[2][0]!=0) {
        return 1;
    }
    
    return 0;
}

void paceX(void){
    scanf("%d", &pace);
    switch (pace) {
        case 1:
            if (net[0][0]==0) {
                net[0][0]=1;
            } else paceX();
            break;
        case 2:
            if (net[1][0]==0) {
                net[1][0]=1;
            } else paceX();
            break;
        case 3:
            if (net[2][0]==0) {
                net[2][0]=1;
            } else paceX();
            break;
        case 4:
            if (net[0][1]==0) {
                net[0][1]=1;
            } else paceX();
            break;
        case 5:
            if (net[1][1]==0) {
                net[1][1]=1;
            } else paceX();
            break;
        case 6:
            if (net[2][1]==0) {
                net[2][1]=1;
            } else paceX();
            break;
        case 7:
            if (net[0][2]==0) {
                net[0][2]=1;
            } else paceX();
            break;
        case 8:
            if (net[1][2]==0) {
                net[1][2]=1;
            } else paceX();
            break;
        case 9:
            if (net[2][2]==0) {
                net[2][2]=1;
            } else paceX();
            break;
            
        default:
            printf("Ты чо дурак блядь?");
            break;
    }
}

void paceO(void){
    scanf("%d", &pace);
    switch (pace) {
        case 1:
            net[0][0]=2;
            break;
        case 2:
            net[1][0]=2;
            break;
        case 3:
            net[2][0]=2;
            break;
        case 4:
            net[0][1]=2;
            break;
        case 5:
            net[1][1]=2;
            break;
        case 6:
            net[2][1]=2;
            break;
        case 7:
            net[0][2]=2;
            break;
        case 8:
            net[1][2]=2;
            break;
        case 9:
            net[2][2]=2;
            break;
            
        default:
            printf("Ты чо дурак блядь?");
            break;
    }
}

_Bool gameLoop(void){
    
    paceX();
    updateGameScreen();
    paceO();
    updateGameScreen();
    paceX();
    updateGameScreen();
    paceO();
    updateGameScreen();
    paceX();
    updateGameScreen();
    if (winTest()) {
        return 1;
    }
    paceO();
    updateGameScreen();
    if (winTest()) {
        return 1;
    }
    paceX();
    updateGameScreen();
    if (winTest()) {
        return 1;
    }
    paceO();
    updateGameScreen();
    if (winTest()) {
        return 1;
    }
    paceX();
    updateGameScreen();
    if (winTest()) {
        return 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    for (char i = 0; i<3; i++) {
        for (char j=0; j<3; j++) {
            net[i][j] = 0;
        }
    }
    
//    net[0][0]=0;    net[1][0]=0;    net[2][0]=0;
//    net[0][1]=0;    net[1][1]=0;    net[2][1]=0;
//    net[0][2]=0;    net[1][2]=0;    net[2][2]=0;
    
    updateGameScreen();
    gameLoop();
    printf("\n");
    
    
    
    if (winTest()) {
        printf("\nПобеда!");
    } else printf("Ничья");
    
    printf("\n");
    return 0;
}
