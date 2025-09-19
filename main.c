#include <stdio.h>
#include <stdlib.h>

int ttt_show_board(){
    char A1='A',A2='A',A3='A',B1='A',B2='A',B3='A',C1='A',C2='A',C3='A';
    system("clear");
	printf("Tic Tac Toe\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n",A1,A2,A3);
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n",B1,B2,B3);
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n",C1,C2,C3);
    printf("|     |     |     |\n");
    printf(" _____ _____ _____\n");
    return 0;
}

int main() {
    printf("Hello World\n");
    return 0;
}