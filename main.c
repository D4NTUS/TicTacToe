#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define X_WON 1
#define O_WON 2
#define DRAW   3

int getch(void) {                           //getch from net :p
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int ttt_show_board(char A[3], char B[3], char C[3]) {
    system("clear");  // use "cls" if Windows
    printf("Tic Tac Toe\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", A[0], A[1], A[2]);
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", B[0], B[1], B[2]);
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", C[0], C[1], C[2]);
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    return 0;
}

int ttt_won(int A[3], int B[3], int C[3]) {
    // X checks
    if ((A[0]==1 && A[1]==1 && A[2]==1) ||
        (B[0]==1 && B[1]==1 && B[2]==1) ||
        (C[0]==1 && C[1]==1 && C[2]==1) ||
        (A[0]==1 && B[0]==1 && C[0]==1) ||
        (A[1]==1 && B[1]==1 && C[1]==1) ||
        (A[2]==1 && B[2]==1 && C[2]==1) ||
        (A[0]==1 && B[1]==1 && C[2]==1) ||
        (A[2]==1 && B[1]==1 && C[0]==1))
        return X_WON;

    // O checks
    if ((A[0]==2 && A[1]==2 && A[2]==2) ||
        (B[0]==2 && B[1]==2 && B[2]==2) ||
        (C[0]==2 && C[1]==2 && C[2]==2) ||
        (A[0]==2 && B[0]==2 && C[0]==2) ||
        (A[1]==2 && B[1]==2 && C[1]==2) ||
        (A[2]==2 && B[2]==2 && C[2]==2) ||
        (A[0]==2 && B[1]==2 && C[2]==2) ||
        (A[2]==2 && B[1]==2 && C[0]==2))
        return O_WON;

    // Draw check
    if ((A[0] && A[1] && A[2]) &&
        (B[0] && B[1] && B[2]) &&
        (C[0] && C[1] && C[2]))
        return DRAW;

    return 0;
}

int ttt_menu(int menu_choice[2], int menu_selected) {
    system("cls");
    printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
    printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
    printf("  |    | |                |   |-----||		      |   |   	||-----\n");
    printf("  |    | |	          |   |     ||                |   |     ||\n");
    printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n");
    printf(" --------------- \n|  Singleplayer |\n --------------- \n   Multiplayer  \n\n     Settings\n\n      Quit     ");
	printf("\n\n----------------------------------------------------------------------------------------------------\nYou play with an Algorithm.");
    int i = 0;
    while (i != '\n') {
        i = getch();
        if (i == 'w' || i == 'W') {
            menu_choice[0]++;
            if (menu_choice[0] > 4) menu_choice[0] = 4;
        }
        else if (i == 's' || i == 'S') {
            menu_choice[0]--;
            if (menu_choice[0] < 1) menu_choice[0] = 1;
        }
        if(menu_choice[0] == 4){
            system("cls");
	        printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
            printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
            printf("  |    | |                |   |-----||		      |   |   	||-----\n");
            printf("  |    | |	          |   |     ||                |   |     ||\n");
            printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n");
            printf(" --------------- \n|  Singleplayer |\n --------------- \n   Multiplayer  \n\n     Settings\n\n      Quit     ");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nYou play with an Algorithm.");
        }
        if(menu_choice[0] == 3){
            system("cls");
	        printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
            printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
            printf("  |    | |                |   |-----||		      |   |   	||-----\n");
            printf("  |    | |	          |   |     ||                |   |     ||\n");
            printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n\n");
            printf("   Singleplayer\n --------------- \n|  Multiplayer  |\n --------------- \n     Settings\n\n      Quit     ");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nYou play with another person on the same computer.");
        }
        if(menu_choice[0] == 2){
            system("cls");
	        printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
            printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
            printf("  |    | |                |   |-----||		      |   |   	||-----\n");
            printf("  |    | |	          |   |     ||                |   |     ||\n");
            printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n\n");
            printf("   Singleplayer\n\n   Multiplayer  \n --------------- \n|    Settings   |\n --------------- \n      Quit     ");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nYou can choose what input you want to use.");
        }
        if(menu_choice[0] == 1){
            system("cls");
	        printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
            printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
            printf("  |    | |                |   |-----||		      |   |   	||-----\n");
            printf("  |    | |	          |   |     ||                |   |     ||\n");
            printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n\n");
            printf("   Singleplayer\n\n   Multiplayer\n\n     Settings \n --------------- \n|     Quit      |\n --------------- ");
	        printf("\n----------------------------------------------------------------------------------------------------\nYou will just leave , what more to expect :D.");
        }
    }
    return menu_selected = menu_choice[0];
}


int main() {
    char A[] = {'1','2','3'};
    char B[] = {'4','5','6'};
    char C[] = {'7','8','9'};

    int SA[] = {0,0,0};
    int SB[] = {0,0,0};
    int SC[] = {0,0,0};

    int menu_choice[] = {4, 0};
    int menu_selected = 0;
    while(menu_selected  != 1){
    ttt_menu(menu_choice, menu_selected);
    }
    menu_selected = 0;   // 4 = singleplayer, 3 = multiplayer, 2 = settings, 1 = quit

    ttt_show_board(A,B,C);

    int result = ttt_won(SA,SB,SC);

    if(result == X_WON) printf("X has won!\n");
    else if(result == O_WON) printf("O has won!\n");
    else if(result == DRAW) printf("Draw!\n");

    return 0;
}