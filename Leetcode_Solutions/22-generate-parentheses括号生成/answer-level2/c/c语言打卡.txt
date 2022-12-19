### 解题思路
动态规划，一个$n$对括号的字符串可以看成"("+$i$对括号字符串+")"+$n-1-i$对括号字符串

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    char** result;
    int currentSize;
    int size;
}solution, *Solution;

Solution create(int n){
    Solution s = (Solution)malloc(sizeof(solution));
    s->size = pow(2, n);
    s->result = (char**)calloc(s->size, sizeof(char*));
    s->currentSize = 0;
    return s;
}

void insert(Solution s, char* str){
    s->result[(s->currentSize) ++] = str;
    if(s->currentSize == s->size){
        s->size *= 2;
        s->result = (char**)realloc(s->result, s->size * sizeof(char*));
    }
}

void generate(char** result, int n, int* returnSize){
    int i, k = *returnSize, kn = *returnSize;
}

void destroy(Solution s){
    int i;
    for(i = 0;i < s->currentSize;i ++)
        free(s->result[i]);
    free(s);
}

char ** generateParenthesis(int n, int* returnSize){
    Solution* memorize = (Solution*)calloc(n + 1, sizeof(Solution));
    int i, j, k, l;
    char* str = (char*)calloc(1, sizeof(char));
    for(i = 0;i <= n;i ++)
        memorize[i] = create(i);
    insert(memorize[0], str);
    for(i = 1;i <= n;i ++)
        for(j = 0;j < i;j ++)
            for(k = 0;k < memorize[j]->currentSize;k ++)
                for(l = 0;l < memorize[i - 1 - j]->currentSize;l ++){
                    str = (char*)calloc(2 * i + 1, sizeof(char));
                    str[0] = '(';
                    strcat(str, memorize[j]->result[k]);
                    str[2 * j + 1] = ')';
                    strcat(str, memorize[i - 1 - j]->result[l]);
                    insert(memorize[i], str);
                }
    for(i = 0;i < n;i ++)
        destroy(memorize[i]);
    *returnSize = memorize[n]->currentSize;
    memorize[n]->result = (char**)realloc(memorize[n]->result, memorize[n]->currentSize * sizeof(char*));
    char** result = memorize[n]->result;
    free(memorize[n]);
    return result;
}
```