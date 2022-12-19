### 解题思路
二维动态规划，$f(i,j)$表示word1的前$i$个字符变为word2的前$j$个字符所需次数

### 代码

```c
#define MIN(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int minDistance(char * word1, char * word2){
    int row = strlen(word1), column = strlen(word2);
    if(row == 0 || column == 0)
        return (row > column ? row : column);
    int i, j, **memorize = (int**)calloc(row, sizeof(int*));
    for(i = 0;i < row;i ++)
        memorize[i] = (int*)calloc(column, sizeof(int));
    bool flag1, flag2;
    if(word1[0] == word2[0]){
        memorize[0][0] = 0;
        flag1 = 1;
        flag2 = 1;
    }
    else{
        memorize[0][0] = 1;
        flag1 = 0;
        flag2 = 0;
    }
    for(j = 1;j < column;j ++)
        if(word1[0] == word2[j] && flag1 == 0){
            flag1 = 1;
            memorize[0][j] = memorize[0][j - 1];
        }
        else
            memorize[0][j] = memorize[0][j - 1] + 1;
    for(i = 1;i < row;i ++)
        if(word1[i] == word2[0] && flag2 == 0){
            flag2 = 1;
            memorize[i][0] = memorize[i - 1][0];
        }
        else
            memorize[i][0] = memorize[i - 1][0] + 1;
    for(i = 1;i < row;i ++)
        for(j = 1;j < column;j ++)
            if(word1[i] == word2[j])
                memorize[i][j] = MIN(memorize[i - 1][j] + 1, memorize[i][j - 1] + 1, memorize[i - 1][j - 1]);
            else
                memorize[i][j] = MIN(memorize[i - 1][j], memorize[i][j - 1], memorize[i - 1][j - 1]) + 1;
    int result = memorize[row - 1][column - 1];
    for(i = 0;i < row;i ++)
        free(memorize[i]);
    free(memorize);
    return result;
}
```