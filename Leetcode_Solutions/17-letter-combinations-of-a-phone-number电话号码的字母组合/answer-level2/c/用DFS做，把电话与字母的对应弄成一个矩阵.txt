### 解题思路
``` 
 #define TOTAL 10000
 #define M 20
 #define N 4
 int g_index = 0;
void dfs(char* digits, char table[][N], int pos, char** ret, char* word) {    
    if (pos == strlen(digits)) {
        for (int i = 0; i < strlen(digits); i++) {
            ret[g_index][i] = word[i];
        } 
        
        g_index++;
        return;
    }

    int index = digits[pos] - '2';

    for (int i = 0; i < N; i++) {
        if (table[index][i] != '0') {
            word[pos] = table[index][i];
            dfs(digits, table, pos + 1, ret, word);
        }
    }

}


char ** letterCombinations(char * digits, int* returnSize){
    char** ret = (char**)calloc(TOTAL, sizeof(char*));
    for (int i = 0; i < TOTAL; i++) {
        ret[i] = (char*)calloc(M + 1, sizeof(char));
    }

    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    g_index = 0;

    char table[M][N] = {{'a', 'b', 'c', '0'}, {'d','e', 'f', '0'}, {'g', 'h', 'i', '0'}, {'j', 'k', 'l', '0'}, {'m', 'n', 'o', '0'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v', '0'}, {'w', 'x', 'y', 'z'}};

    char* word = calloc(M + 1, sizeof(char));

    dfs(digits, table, 0, ret, word);

    *returnSize = g_index;
    return ret;
    
}
```
