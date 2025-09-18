#include <stdio.h>
#include <stdlib.h>

int tttshowboard(){
    char A1='A',A2='A',A3='A',B1='A',B2='A',B3='A',C1='A',C2='A',C3='A';
    system("clear");
	printf("Tic Tac Toe\n _____ _____ _____\n|     |     |     |\n|  %c  |  %c  |  %c  |\n|     |     |     |\n _____ _____ _____\n|     |     |     |\n|  %c  |  %c  |  %c  |\n|     |     |     |\n _____ _____ _____\n|     |     |     |\n|  %c  |  %c  |  %c  |\n|     |     |     |\n _____ _____ _____\n",A1,A2,A3,B1,B2,B3,C1,C2,C3);
    return 0;
}

int main() {
    printf("Hello World\n");
    return 0;
}