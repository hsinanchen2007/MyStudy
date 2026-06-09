### 解题思路
如何记录一个符合要求的结果：
`int *result = (int *)malloc((len + 1) * sizeof(int));`
记录在字符串s中的下标范围，而不是记录字符串。
result[i] 表示子串以s[i]结尾，那么这个子串就是从result[i-1] + 1 ~ result[i]

### 代码

```c
int isHui(char *s, int start, int end)
{
    while (start <= end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void dfs(char *s, int pos, char ***res, int *returnSize, int *result, int idx, int *returnColSizes)
{
    if (s[pos] == '\0') { //匹配到s的结尾了
        res[*returnSize] = (char **)malloc((idx - 1) * sizeof(char *));
        for (int i = 1; i < idx; i++) {
            res[*returnSize][i - 1] = (char *)malloc(sizeof(char) * (result[i] - result[i - 1] + 1)); //加1是因为\0
            int k = 0;
            for(int j = result[i - 1] + 1; j <= result[i]; j++) {
                res[*returnSize][i - 1][k++] = s[j];
            }
            res[*returnSize][i - 1][k] = '\0';
        }
        returnColSizes[*returnSize] = idx - 1;
        (*returnSize)++;
    }
    
    for(int i = pos; s[i] != '\0'; i++){
        if(isHui(s, pos, i)){
            result[idx] = i;
            dfs(s, i + 1, res, returnSize, result, idx + 1, returnColSizes);
        }
    }
}

#define MAX_SIZE 1024
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    int len = strlen(s);
    char ***res = (char ***)malloc(MAX_SIZE * sizeof(char **));
    *returnColumnSizes = (int *)malloc(MAX_SIZE *sizeof(int));
    
    int *result = (int *)malloc((len + 1) * sizeof(int));
    result[0] = -1;
    
    *returnSize = 0;
    dfs(s, 0, res, returnSize, result, 1, *returnColumnSizes);
    return res;
}

```