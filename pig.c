#include "names.h"

#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Set up pig
    typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
    const Position pig[7] = { SIDE, SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER, JOWLER };

    // Set up players
    int num_players, num;
    printf("How many players? ");
    num = scanf("%d", &num_players);
    // validate number of players
    if ((num == 0) || (num_players < 2) || (num_players > 10)) {
        fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
        num_players = 2;
    }

    // Set up points for all the players
    char points[10];
    for (int person = 0; person < num_players; person += 1) {
        points[person] = 0;
    }

    // Set up seed
    uint64_t seed;
    int num_two;
    printf("Random seed: ");
    num_two = scanf("%lu", &seed);
    // validate seed number
    if ((num_two == 0) || (seed < 0) || (seed > UINT_MAX)) {
        fprintf(stderr, "Invalid random seed. Using 2021 instead.\n");
        seed = 2021;
    }

    // Set up initial point for randomization of seeds
    srandom(seed);

    // Begin the actual game
    int win = 0;
    while (win != 1) {
        // loop through each player as long as no one has won yet
        for (int player = 0; player < num_players; player += 1) {
            // Announce who is rolling the pig
            printf("%s rolls the pig...", names[player]);
            int end_of_round = 0;
            // begin players turn, and keep rolling until it's the end of their round
            while ((end_of_round != 1) && (win == 0)) {
                // roll a random position and update points
                switch (pig[random() % 7]) {
                case JOWLER:
                    // player gets 5 points if pig lands on ear
                    printf(" pig lands on ear");
                    points[player] += 5;
                    break;
                case RAZORBACK:
                    // player gets 10 points if pig lands on back
                    printf(" pig lands on back");
                    points[player] += 10;
                    break;
                case TROTTER:
                    // player gets 10 points if pig lands upright
                    printf(" pig lands upright");
                    points[player] += 10;
                    break;
                case SNOUTER:
                    // player gets 15 points if pig lands on snout
                    printf(" pig lands on snout");
                    points[player] += 15;
                    break;
                default:
                    // pig rolls on side, then end turn
                    printf(" pig lands on side\n");
                    points[player] += 0;
                    end_of_round = 1;
                    break;
                }
                // if the player has 100 or more points, they win
                if (points[player] >= 100) {
                    printf("\n%s wins with %d points!\n", names[player], points[player]);
                    win = 1;
                    break;
                }
            }
            // break out of the for loop if there is a winner
            if (win == 1) {
                break;
            }
        }
    }
    return 0;
}
