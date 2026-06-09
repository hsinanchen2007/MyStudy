### 解题思路
![image.png](https://pic.leetcode-cn.com/f89401141d8c68a285bb0a8c20e69a08b3507d9d970b4f6d4c46505002c370ac-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** g_ret = NULL;
char* g_result = NULL;
int g_index;

void dfs(char* digits, int step, char* result, char** list){
    if(step == strlen(digits)) {
        g_ret[g_index] = (char*)malloc(sizeof(int) * (strlen(digits) + 1));
        sprintf(g_ret[g_index], "%s", g_result);
        g_index++;
        return;
    }
    for(int i = 0; i < strlen(list[digits[step] - '2']); i++) {
        g_result[step] = list[digits[step] - '2'][i];
        dfs(digits, step + 1, g_result, list);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    int len = strlen(digits);
    char* ret = NULL;
    if(len == 0) {
        *returnSize = 0;
        return &ret;
    }
    int i, j;
    g_result = (char*)malloc(sizeof(char) * (len + 1));
    g_result[len] = '\0';
    g_ret = (char**)malloc(sizeof(char*) * 100000);
    g_index = 0;

    char** list = (char**)malloc(sizeof(char*) * 8);
    for(i = 0; i < 5; i++) {
        list[i] = (char*)malloc(sizeof(char) * 4);
        list[i][3] ='\0';
    }
    list[5] = (char*)malloc(sizeof(char) * 5);
    list[5][4] ='\0';
    list[6] = (char*)malloc(sizeof(char) * 4);
    list[6][3] ='\0';
    list[7] = (char*)malloc(sizeof(char) * 5);
    list[7][4] ='\0';
    int k = 0;
    for(i = 0; i < 8; i++) {
        for(j = 0; j < strlen(list[i]); j++) {
            list[i][j] = k + 'a';
            k++;
        }
    }

    dfs(digits, 0, g_result, list);
    *returnSize = g_index;
    return g_ret;
}
```