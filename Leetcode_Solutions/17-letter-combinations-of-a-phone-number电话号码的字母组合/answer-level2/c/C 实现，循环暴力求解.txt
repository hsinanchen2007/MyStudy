感觉自己的解法太不优雅
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#define NUM 8

char ** letterCombinations(char * digits, int* returnSize) {
    if (*digits == 0) {
        *returnSize = 0;
        return NULL;
    }

    int size[NUM] = {3, 3, 3, 3, 3, 4, 3, 4};
    char ** map = (char **) malloc(sizeof(char *) * NUM);
    char * button;
    char c = 'a';
    // 构造按键数字与字母的映射表
    for (int i = 0; i < NUM; i++) {
        button = (char *) malloc(sizeof(char) * size[i]);
        for (int j = 0; j < size[i]; j++)
            button[j] = c++;
        map[i] = button;
    }

    int len = 0;
    int nums = 1;
    while (digits[len]) {
        nums *= size[digits[len] - '2'];
        len++;
    }

    char ** ret = (char **) malloc(sizeof(char *) * nums);
    for (int i = 0; i < nums; i++) {
        ret[i] = (char *) malloc(sizeof(char) * (len + 1));
        ret[i][len] = 0;
    }
    int index;
    int group = 1;
    int repeat = nums;
    for (int i = 0; i < len; i++) {
        index = digits[i] - '2';
        repeat /= size[index];
        for (int j = 0; j < size[index]; j++) {
            for (int k = 0; k < group; k++) {
                for (int l = 0; l < repeat; l++) {
                    ret[k * repeat * size[index] + repeat * j + l][i] = map[index][j];
                }
            }
        }
        group *= size[index];
    }
    for (int i = 0; i < NUM; i++) {
        free(map[i]);
    }
    free(map);
    *returnSize = nums;
    return ret;
}

int main(int argc, char *argv[])
{
    int returnSize;
    char ** ret = letterCombinations("2388945", &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", ret[i]);
        free(ret[i]);
    }
    free(ret);
    return 0;
}
```