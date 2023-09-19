#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARDS 52

int cards[NUM_CARDS];
int activeCards = NUM_CARDS;

void readchar(const char* msg, char* dest) {
    printf(msg);
    scanf("%c", dest);
    while(getchar() != '\n');
}

void initGame(int* sum) {
    int cardType = 1;

    for(int i = 0; i < NUM_CARDS; i++) {
        cards[i] = cardType++;
        if(cardType > 13) cardType = 1;
    }

    *sum = 0;
    activeCards = NUM_CARDS;
}

/*
void printCards() {
    for(int i = 0; i < NUM_CARDS; i++) {
        printf("%d ", cards[i]);
    }
    putchar('\n');
}
*/

void throwAway(int index) {
    for(int i = index; i < activeCards; i++) {
        cards[i] = cards[i+1];
    }
}

int withdrawCard() {
    int index  = rand() % activeCards--;
    int num = cards[index];

    printf("\nYou got the number %d\n", num);
    throwAway(index);

    return num;
}

void play(int * sum) {
    do {
        //printCards();
        char confirm;
        readchar("\nDo wanna get a card? ", &confirm);

        if(tolower(confirm) == 'y') {
            *sum += withdrawCard();
            printf("The actual sum is %d\n", *sum);
        } else break;

    } while(*sum < 21);
}

void clearscr() {
    printf("\x1b[2J");
    printf("\x1b[H");
}

int main() {
    srand(time(NULL));

    char continueplay = 'y';
    int sum = 0;

    do {
        clearscr();
        initGame(&sum);
        play(&sum);

        if(sum == 21) {
            printf("\nYOU WON!!\n\n");
        }
        else {
            printf("\nYou lost\n\n");
        }

        readchar("Do you wanna play again? ", &continueplay);
        
    } while(tolower(continueplay) == 'y');

    return EXIT_SUCCESS;
}