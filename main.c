#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

#define X_WON 1
#define O_WON 2
#define DRAW 3

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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
    clear_screen();
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

int place(char A[3], char B[3], char C[3], char who_goes, int input) {
    for(int i = 0; i < 10; i++){
        if((input==i) && ((A[i] != 'X') || (A[i] != 'O'))){
            A[i] = who_goes;
            if (who_goes == 'X') who_goes = 'O';
            else who_goes = 'X';
            return who_goes;
        }
        else{
            ttt_show_board( A, B, C);
            printf("Its O's turn\n");
            printf("Its O's turn\n");
            return 1;
        }
    }
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

int menu_main(int menu_choice) {
    clear_screen();
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
            menu_choice++;
            if (menu_choice > 4) menu_choice = 4;
        }
        else if (i == 's' || i == 'S') {
            menu_choice--;
            if (menu_choice < 1) menu_choice = 1;
        }
        if(menu_choice == 4){
            clear_screen();
	        printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
            printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
            printf("  |    | |                |   |-----||		      |   |   	||-----\n");
            printf("  |    | |	          |   |     ||                |   |     ||\n");
            printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n");
            printf(" --------------- \n|  Singleplayer |\n --------------- \n   Multiplayer  \n\n     Settings\n\n      Quit     ");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nYou play with an Algorithm.");
        }
        if(menu_choice == 3){
            clear_screen();
	        printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
            printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
            printf("  |    | |                |   |-----||		      |   |   	||-----\n");
            printf("  |    | |	          |   |     ||                |   |     ||\n");
            printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n\n");
            printf("   Singleplayer\n --------------- \n|  Multiplayer  |\n --------------- \n     Settings\n\n      Quit     ");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nYou play with another person on the same computer.");
        }
        if(menu_choice == 2){
            clear_screen();
	        printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
            printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
            printf("  |    | |                |   |-----||		      |   |   	||-----\n");
            printf("  |    | |	          |   |     ||                |   |     ||\n");
            printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n\n");
            printf("   Singleplayer\n\n   Multiplayer  \n --------------- \n|    Settings   |\n --------------- \n      Quit     ");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nYou can choose what input you want to use.");
        }
        if(menu_choice == 1){
            clear_screen();
	        printf("-----     -----         -----  -----  -----         -----  -----  -----\n");
            printf("  |    | |      	  |   |     ||	              |	  |     ||\n");
            printf("  |    | |                |   |-----||		      |   |   	||-----\n");
            printf("  |    | |	          |   |     ||                |   |     ||\n");
            printf("  |    |  -----	          |   |     | -----	      |    -----  ----- \n\n\n");
            printf("   Singleplayer\n\n   Multiplayer\n\n     Settings \n --------------- \n|     Quit      |\n --------------- ");
	        printf("\n----------------------------------------------------------------------------------------------------\nYou will just leave , what more to expect :D.");
        }
    }
    return menu_choice;
}

int menu_settings(int menu_choice) {
    clear_screen();
	printf(" --------------- \n|    Numpad     |\n --------------- \n    Keyboard\n\n      Back");
	printf("\n\n----------------------------------------------------------------------------------------------------\n");
    printf("Layout : \n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  7  |  8  |  9  |\n");
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  4  |  5  |  6  |\n");
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  1  |  2  |  3  |\n");
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    int i = 0;
    while (i != '\n') {
        i = getch();
        if (i == 'w' || i == 'W') {
            menu_choice++;
            if (menu_choice > 3) menu_choice = 3;
        }
        else if (i == 's' || i == 'S') {
            menu_choice--;
            if (menu_choice < 1) menu_choice = 1;
        }
        if(menu_choice == 3){
            clear_screen();
		    printf(" --------------- \n|    Numpad     |\n --------------- \n    Keyboard\n\n      Back");
	        printf("\n\n----------------------------------------------------------------------------------------------------\n");
            printf("Layout : \n");
            printf(" _____ _____ _____\n");
            printf("|     |     |     |\n");
            printf("|  7  |  8  |  9  |\n");
            printf("|     |     |     |\n");
            printf(" _____ _____ _____\n");
            printf("|     |     |     |\n");
            printf("|  4  |  5  |  6  |\n");
            printf("|     |     |     |\n");
            printf(" _____ _____ _____\n");
            printf("|     |     |     |\n");
            printf("|  1  |  2  |  3  |\n");
            printf("|     |     |     |\n");
            printf(" _____ _____ _____\n");
        }
        if(menu_choice == 2){
            clear_screen();
	        printf("\n     Numpad\n --------------- \n|   Keyboard    |\n --------------- \n      Back");
	        printf("\n\n----------------------------------------------------------------------------------------------------\n");
            printf("Layout : \n");
            printf(" _____ _____ _____\n");
            printf("|     |     |     |\n");
            printf("|  1  |  2  |  3  |\n");
            printf("|     |     |     |\n");
            printf(" _____ _____ _____\n");
            printf("|     |     |     |\n");
            printf("|  4  |  5  |  6  |\n");
            printf("|     |     |     |\n");
            printf(" _____ _____ _____\n");
            printf("|     |     |     |\n");
            printf("|  7  |  8  |  9  |\n");
            printf("|     |     |     |\n");
            printf(" _____ _____ _____\n");
        }
        if(menu_choice == 1){
            clear_screen();
	        printf("\n     Numpad\n\n    Keyboard\n --------------- \n|     Back      |\n --------------- ");
	        printf("\n----------------------------------------------------------------------------------------------------\n");
            printf("Back to main menu.");
	    }
    }
    return menu_choice;
}

int singleplayer_menu(int menu_choice) {
    clear_screen();
	printf(" --------------- \n|     Easy      |\n --------------- \n     Medium\n\n      Hard\n\n      Back");
	printf("\n\n----------------------------------------------------------------------------------------------------\nEvery choose is random.");
    int i = 0;
    while (i != '\n') {
        i = getch();
        if (i == 'w' || i == 'W') {
            menu_choice++;
            if (menu_choice > 4) menu_choice = 4;
        }
        else if (i == 's' || i == 'S') {
            menu_choice--;
            if (menu_choice < 1) menu_choice = 1;
        }
        if(menu_choice == 4){
            clear_screen();
	        printf(" --------------- \n|     Easy      |\n --------------- \n     Medium\n\n      Hard\n\n      Back");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nEvery choose is random.");
        }
        if(menu_choice == 3){
            clear_screen();
	        printf("\n      Easy\n --------------- \n|    Medium     |\n --------------- \n      Hard\n\n      Back");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nAlmost like hard mod except you start fist.");
        }
        if(menu_choice == 2){
            clear_screen();
            printf("\n      Easy\n\n     Medium\n --------------- \n|     Hard      |\n --------------- \n      Back");
	        printf("\n\n----------------------------------------------------------------------------------------------------\nIt uses complicated algorithm to win.");
	    }
        if(menu_choice == 1){
            clear_screen();
	        printf("\n      Easy\n\n     Medium\n\n      Hard\n --------------- \n|     Back      |\n --------------- ");
	        printf("\n----------------------------------------------------------------------------------------------------\nBack to main menu.");
	    }
    }
    return menu_choice;
}

int multiplayer(char A[3], char B[3], char C[3]) {
    int SA[] = {0,0,0};
    int SB[] = {0,0,0};
    int SC[] = {0,0,0};
    srand(time(0));
    int random = rand() % 2;
    char who_goes;
    if (random == 1) who_goes = 'O';
    else who_goes = 'X';
    int game_ongoing = 1;
    int input = 0;
    while(game_ongoing == 1){
        if(who_goes == 'O'){
            ttt_show_board( A, B, C);
            printf("Its O's turn\n");
            input = getch();
            place( A, B, C, who_goes, input);
        }
        else{
            ttt_show_board(A,B,C);
            printf("Its X's turn\n");
            input = getch();
            place( A, B, C, who_goes, input);
        }
    }
    int result = ttt_won(SA,SB,SC);

    if(result == X_WON) printf("X has won!\n");
    else if(result == O_WON) printf("O has won!\n");
    else if(result == DRAW) printf("Draw!\n");
    return 0;
}

int main() {
    char A[] = {'1','2','3'};
    char B[] = {'4','5','6'};
    char C[] = {'7','8','9'};
    int game_running = 1;
    while(game_running == 1){
        int menu_choice = 4;         // 4 = singleplayer, 3 = multiplayer, 2 = settings, 1 = quit
        menu_choice = menu_main(menu_choice);
        if(menu_choice == 1){
            game_running = 0;
        }
        else if(menu_choice == 2) {
            menu_choice = 3;
            menu_choice = menu_settings(menu_choice);
            if(menu_choice == 2){
                A[0] = '1'; A[1] = '2'; A[2] = '3';
                B[0] = '4'; B[1] = '5'; B[2] = '6';
                C[0] = '7'; C[1] = '8'; C[2] = '9';
            }
            else if(menu_choice == 3){
                A[0] = '7'; A[1] = '8'; A[2] = '9';
                B[0] = '4'; B[1] = '5'; B[2] = '6';
                C[0] = '1'; C[1] = '2'; C[2] = '3';
            }
        }
        else if(menu_choice == 3){
            multiplayer(A,B,C);
        }
        else if(menu_choice == 4){
            menu_choice = 4;
            menu_choice = singleplayer_menu(menu_choice);
            if(menu_choice == 4){
                //easy random
            }
            else if(menu_choice == 3){
                //medium
            }
            else if(menu_choice == 2){
                //hard
            }
        }
    }
    return 0;
}