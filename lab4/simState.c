#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool findreachable(int current, int fsm[8][2], bool *unreachable, bool deleted[8]) {
    int stack[16] = {current};
    int top = 0;
    while (top >= 0) {
        int current = stack[top];
        top--;
        if (!unreachable[current]) {
            if (!deleted[current]) {
                unreachable[current] = true;
                stack[++top] = fsm[current][0];
                stack[++top] = fsm[current][1];
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < 8; i++) {
        if (!unreachable[i]) {
            if (!deleted[i]) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main(int argc, char * argv[]) {
    
    int fsm[8][2] = {{5, 2}, {7, 3}, {1, 5}, {0, 3}, {2, 7}, {4, 6}, {3, 4}, {6, 1}};
    int current = 0;
    bool deleted[8] = {false};
    printf("A\n");
    char input[5];
    while (true) {
        fgets(input, 6, stdin);
        if (input[0] == '0' || input[0] == '1') {
            current = fsm[current][input[0] - 48];
            printf("%c\n", current + 65);
        }
        else if (input[0] == 'c') {
            if (65 <= input[4] && input[4] <= 72 && 48 <= input[2] && input[2] <= 49){
                if (!deleted[input[4] - 65]) {
                    fsm[current][input[2] - 48] = input[4] - 65;
                }
            }
        }
        else if (input[0] == 'p') {
            for (int i = 0; i < 8; i++) {
                if (!deleted[i]) {
                    printf("%c %c %c\n", i + 65, fsm[i][0] + 65, fsm[i][1] + 65);
                }
            }
        }
        else if (input[0] == 'g') {
            bool unreachable[8] = {false};
            bool flag = findreachable(current, fsm, unreachable, deleted);
            if (!flag) {
                printf("Garbage: ");
                for (int i = 0; i < 8; i++) {
                    if (!deleted[i]) {
                        if (!unreachable[i]) {
                            printf("%c ", i + 65);
                        }
                    }
                }
                printf("\n");
            }
            else {
                printf("No garbage\n");
            }
        }
        else if (input[0] == 'd') {
            if (65 <= input[2] && input[2] <= 72) {
                if (!deleted[input[2] - 65]) {
                    bool unreachable[8] = {false};
                    bool flag = findreachable(current, fsm, unreachable, deleted);
                    if (!unreachable[input[2] - 65]) {
                        deleted[input[2] - 65] = true;
                        printf("Deleted.\n", input[2]);
                    }
                }
            }
            else {
                bool unreachable[8] = {false};
                bool flag = findreachable(current, fsm, unreachable, deleted);
                if (!flag) {
                    printf("Deleted: ");
                    for (int i = 0; i < 8; i++) {
                        if (!deleted[i]) {
                            if (!unreachable[i]) {
                                deleted[i] = true;
                                printf("%c ", i + 65);
                            }
                        }
                    }
                    printf("\n");
                }
                else {
                    printf("No deleted states\n");
                }
            }

        }

        else if (input[0] == 'q') {
            break;
        }
        
    }
    exit(0);
}

