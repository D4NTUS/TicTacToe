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

char *ttt_cell(char A[3], char B[3], char C[3], int i) {
    if (i < 3) return &A[i];
    if (i < 6) return &B[i - 3];
    return &C[i - 6];
}

int ttt_is_free(char c) {
    return c != 'X' && c != 'O';
}

int place(char A[3], char B[3], char C[3], char who_goes, int input) {
    for(int i = 0; i < 9; i++){
        char *c = ttt_cell(A, B, C, i);
        if(*c == input && ttt_is_free(*c)){
            *c = who_goes;
            return 1;
        }
    }
    return 0;                               // key was not a free cell
}

int ttt_won(char A[3], char B[3], char C[3]) {
    // X checks
    if ((A[0]=='X' && A[1]=='X' && A[2]=='X') ||
        (B[0]=='X' && B[1]=='X' && B[2]=='X') ||
        (C[0]=='X' && C[1]=='X' && C[2]=='X') ||
        (A[0]=='X' && B[0]=='X' && C[0]=='X') ||
        (A[1]=='X' && B[1]=='X' && C[1]=='X') ||
        (A[2]=='X' && B[2]=='X' && C[2]=='X') ||
        (A[0]=='X' && B[1]=='X' && C[2]=='X') ||
        (A[2]=='X' && B[1]=='X' && C[0]=='X'))
        return X_WON;

    // O checks
    if ((A[0]=='O' && A[1]=='O' && A[2]=='O') ||
        (B[0]=='O' && B[1]=='O' && B[2]=='O') ||
        (C[0]=='O' && C[1]=='O' && C[2]=='O') ||
        (A[0]=='O' && B[0]=='O' && C[0]=='O') ||
        (A[1]=='O' && B[1]=='O' && C[1]=='O') ||
        (A[2]=='O' && B[2]=='O' && C[2]=='O') ||
        (A[0]=='O' && B[1]=='O' && C[2]=='O') ||
        (A[2]=='O' && B[1]=='O' && C[0]=='O'))
        return O_WON;

    // Draw check - no free cell left
    for (int i = 0; i < 9; i++)
        if (ttt_is_free(*ttt_cell(A, B, C, i)))
            return 0;
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

// Minimax: AI plays 'O', human plays 'X'. Positive score = good for O.
int minimax(char A[3], char B[3], char C[3], char who_goes, int depth) {
    int result = ttt_won(A, B, C);
    if (result == O_WON) return 10 - depth;
    if (result == X_WON) return depth - 10;
    if (result == DRAW) return 0;

    int best = (who_goes == 'O') ? -100 : 100;
    for (int i = 0; i < 9; i++) {
        char *c = ttt_cell(A, B, C, i);
        if (!ttt_is_free(*c)) continue;
        char saved = *c;
        *c = who_goes;
        int score = minimax(A, B, C, who_goes == 'O' ? 'X' : 'O', depth + 1);
        *c = saved;
        if (who_goes == 'O' && score > best) best = score;
        if (who_goes == 'X' && score < best) best = score;
    }
    return best;
}

int ai_random_move(char A[3], char B[3], char C[3]) {
    int free_cells[9];
    int count = 0;
    for (int i = 0; i < 9; i++)
        if (ttt_is_free(*ttt_cell(A, B, C, i))) free_cells[count++] = i;
    return free_cells[rand() % count];
}

int ai_best_move(char A[3], char B[3], char C[3]) {
    int best_moves[9];
    int count = 0;
    int best = -100;
    for (int i = 0; i < 9; i++) {
        char *c = ttt_cell(A, B, C, i);
        if (!ttt_is_free(*c)) continue;
        char saved = *c;
        *c = 'O';
        int score = minimax(A, B, C, 'X', 1);
        *c = saved;
        if (score > best) {
            best = score;
            count = 0;
        }
        if (score == best) best_moves[count++] = i;
    }
    return best_moves[rand() % count];    // pick randomly among equally good moves
}

// ai: 0 = no AI (multiplayer), EASY = random moves, HARD = minimax
#define EASY 1
#define HARD 2

int play_game(char A[3], char B[3], char C[3], char who_goes, int ai) {
    int result = 0;
    while(result == 0){
        ttt_show_board(A, B, C);
        if(ai && who_goes == 'O'){
            int move = (ai == HARD) ? ai_best_move(A, B, C) : ai_random_move(A, B, C);
            *ttt_cell(A, B, C, move) = 'O';
        }
        else{
            printf("Its %c's turn\n", who_goes);
            int input = getch();
            if(!place(A, B, C, who_goes, input)) continue;   // invalid key, ask again
        }
        who_goes = (who_goes == 'X') ? 'O' : 'X';
        result = ttt_won(A, B, C);
    }

    ttt_show_board(A, B, C);
    if(result == X_WON) printf(ai ? "You have won!\n" : "X has won!\n");
    else if(result == O_WON) printf(ai ? "The computer has won!\n" : "O has won!\n");
    else printf("Draw!\n");
    printf("Press Enter to continue...");
    while(getch() != '\n');
    return result;
}

int multiplayer(char A[3], char B[3], char C[3]) {
    char who_goes = (rand() % 2) ? 'O' : 'X';
    return play_game(A, B, C, who_goes, 0);
}

void reset_board(char A[3], char B[3], char C[3], int numpad) {
    A[0] = '1'; A[1] = '2'; A[2] = '3';
    B[0] = '4'; B[1] = '5'; B[2] = '6';
    C[0] = '7'; C[1] = '8'; C[2] = '9';
    if(numpad){
        A[0] = '7'; A[1] = '8'; A[2] = '9';
        C[0] = '1'; C[1] = '2'; C[2] = '3';
    }
}

int main() {
    char A[3], B[3], C[3];
    int numpad = 0;
    reset_board(A, B, C, numpad);
    srand(time(0));
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
            if(menu_choice == 2) numpad = 0;
            else if(menu_choice == 3) numpad = 1;
        }
        else if(menu_choice == 3){
            reset_board(A, B, C, numpad);
            multiplayer(A,B,C);
        }
        else if(menu_choice == 4){
            menu_choice = 4;
            menu_choice = singleplayer_menu(menu_choice);
            reset_board(A, B, C, numpad);
            if(menu_choice == 4){
                //easy - random moves, random starter
                play_game(A, B, C, (rand() % 2) ? 'O' : 'X', EASY);
            }
            else if(menu_choice == 3){
                //medium - minimax, you start first
                play_game(A, B, C, 'X', HARD);
            }
            else if(menu_choice == 2){
                //hard - minimax, computer starts first
                play_game(A, B, C, 'O', HARD);
            }
        }
    }
    return 0;
}
