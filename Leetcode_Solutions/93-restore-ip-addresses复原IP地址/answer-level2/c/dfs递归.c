```
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isValid(char* s, int len)
{
    if (len <= 0 || len > 3)
        return false;
    if (len != 1 && *(s) == '0')
        return false;

    int number = 0;
    for (int i = 0; i < len; i++) {
        number = (number * 10) + (*(s + i) - '0');
    }

    if (number >= 0 && number <= 255) {
        return true;
    } else {
        return false;
    }
}

void dfs(char* str, int level, char** answer, int* returnSize, char** result)
{
    int len = strlen(str);
    if (len == 0)
        return;
    if (level > 3)
        return;

    if (level == 3) {
        if ((strlen(str) == 1 && isValid(str, 1)) || (strlen(str) == 2 && isValid(str, 2)) || (strlen(str) == 3 && isValid(str, 3))) {
            // get an answer
             result[*returnSize] = (char*)malloc(strlen(answer[0]) + strlen(answer[1]) + strlen(answer[2]) + strlen(str) + 3 + 1); // 加上三个.以及最后一个'\0'            
            int tmp = 0;

            strncpy(result[*returnSize] + tmp, answer[0], strlen(answer[0]));
            tmp += strlen(answer[0]);

            strncpy(result[*returnSize] + tmp, ".", 1);
            tmp++;

            strncpy(result[*returnSize] + tmp, answer[1], strlen(answer[1]));
            tmp += strlen(answer[1]);

            strncpy(result[*returnSize] + tmp, ".", 1);
            tmp++;

            strncpy(result[*returnSize] + tmp, answer[2], strlen(answer[2]));
            tmp += strlen(answer[2]);

            strncpy(result[*returnSize] + tmp, ".", 1);
            tmp++;

            strncpy(result[*returnSize] + tmp, str, strlen(str));
            tmp += strlen(str);

            *(result[*returnSize] + tmp) = '\0';

            (*returnSize)++;
       }
    }

    if (strlen(str) >= 1 && isValid(str, 1)) {
        strncpy(answer[level], str, 1);
        dfs(str + 1, level + 1, answer, returnSize, result);
    }
    if (strlen(str) >= 2 && isValid(str, 2)) {
        strncpy(answer[level], str, 2);
        dfs(str + 2, level + 1, answer, returnSize, result);
    }
    if (strlen(str) >= 3 && isValid(str, 3)) {
        strncpy(answer[level], str, 3);
        dfs(str + 3, level + 1, answer, returnSize, result);
    }

    memset(answer[level], 0, 4);
}

char** restoreIpAddresses(char* str, int* returnSize)
{
    char** result = (char**)malloc(1000 * sizeof(char*));
    
    *returnSize = 0;
    char** answer = (char**)malloc(4 * sizeof(char*));
    for (int i = 0; i < 4; i++) {
        answer[i] = (char*)calloc(4, sizeof(char));
    }
    dfs(str, 0, answer, returnSize, result);

    for (int i = 0; i < 4; i++) {
        free(answer[i]);
    }
    free(answer);
    
    return result;
}

```
