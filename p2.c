#include <stdio.h>

void printCombinations(int score, int td, int fg, int safety, int td_2pt, int td_fg) { //print combination in format
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
}

void findCombinations(int score) {  //function to find combination just with nested loops
    int td_2pt, td_fg, td, fg, safety;
    printf("possible combinations of scoring plays:\n");
    for (td_2pt = 0; td_2pt <= score / 8; td_2pt++) {
        for (td_fg = 0; td_fg <= score / 7; td_fg++) {
            for (td = 0; td <= (score - (8 * td_2pt) - (7 * td_fg)) / 6; td++) {
                for (fg = 0; fg <= (score - (8 * td_2pt) - (7 * td_fg) - (6 * td)) / 3; fg++) {
                    safety = (score - (8 * td_2pt) - (7 * td_fg) - (6 * td) - (3 * fg)) / 2;
                    if ((8 * td_2pt) + (7 * td_fg) + (6 * td) + (3 * fg) + (2 * safety) == score) {
                        printCombinations(score, td, fg, safety, td_2pt, td_fg);
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        findCombinations(score);
    }
    return 0;
}