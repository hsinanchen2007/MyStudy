#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RET_SIZE 2000

typedef struct brace {
    char digit;
    int value;
} Brace;

Brace brace[] = {
    {
        '(', -1
    },
    {
        ')', 1
    }
};

void find_result(char** ret_matrix, int* returnSize, char* result, int total_num, int curr_num, int curr_sum)
{
    int i = 0;
    if (curr_num >= total_num && curr_sum == 0) {
        result[curr_num] = '\0';
        strcpy(ret_matrix[*returnSize], result);
        (*returnSize)++;//必须加括号
        return;
    } else if (curr_num >= total_num) {
        return;
    }

    while (i < 2) {
        result[curr_num] = brace[i].digit;
        if (curr_sum + brace[i].value > 0) {
            return;
        }
        find_result(ret_matrix, returnSize, result, total_num, curr_num + 1, curr_sum + brace[i].value);
        i++;
    }
}
char ** generateParenthesis(int n, int* returnSize){
    int i = 0;
    *returnSize = 0;
    if (n == 0) {
        return NULL;
    }
    char* result = malloc(sizeof(char) * (2 * n + 1));
    memset(result, 0 , sizeof(char) * (2 * n + 1));
    char** ret_matrix = (char**)malloc(sizeof(char*) * MAX_RET_SIZE);


    for (i = 0; i < MAX_RET_SIZE; i++) {
        ret_matrix[i] = (char*)malloc(sizeof(char) * (2 * n + 1));
        memset(ret_matrix[i], '\0' , sizeof(char) * (2 * n + 1));
    }

    find_result(ret_matrix, returnSize, result, 2 * n, 0, 0);

    return ret_matrix;
}