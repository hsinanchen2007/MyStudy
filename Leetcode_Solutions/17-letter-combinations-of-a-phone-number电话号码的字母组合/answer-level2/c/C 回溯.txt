```

const char *table[] = {
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};

void backTrace(char *digits, int *returnSize, char *path, int index, char **ret)
{
    if(digits[index] == 0)
    {
        int retIndex = (*returnSize)++;
        ret[retIndex] = malloc(strlen(path) + 1);
        strcpy(ret[retIndex], path);
        return;
    }

    int tableIndex = digits[index] - '2';

    for(int i = 0; i < strlen(table[tableIndex]); i++)
    {
        path[index] = table[tableIndex][i];
        backTrace(digits, returnSize, path, index + 1, ret);
    }
}

#define MAX_LEN 1000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){

    *returnSize = 0;

    if(*digits == 0) return NULL;

    char **ret = malloc(sizeof(char *) * MAX_LEN);

    int digiLen = strlen(digits);
    char *path = malloc(digiLen + 1);
    path[digiLen] = 0;

    backTrace(digits, returnSize, path, 0, ret);

    free(path);

    return ret;
}










```
