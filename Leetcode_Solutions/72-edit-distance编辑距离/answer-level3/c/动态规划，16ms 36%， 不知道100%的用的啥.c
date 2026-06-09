### 解题思路
此处撰写解题思路

### 代码

```c

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minDistance(char * word1, char * word2){
    int i,j,max_len;
    int steps = 0;    
    int ret = 0, temp = 0;
    int row = strlen(word1) + 1;
    int col = strlen(word2) + 1;
    int (*dp)[col];
    dp = (int (*)[col])malloc(sizeof(int) * col * row);

    // dp matrixs
    // dp[i][j] = StepMin(word1[0:i], word1[0:j])
    // padding two '' at word beginning as boundary:


    // '' to word1[0:row] and word2[0:col]
    // step('' => a) = insert strlen(a) times
    max_len = MAX(col, row);
    for(i = 0; i < max_len; i++)
    {
        if(i < row)dp[i][0] = i;
        if(i < col)dp[0][i] = i;
    }   

    for (i = 1; i < row; i++){
        for(j = 1; j < col; j++){
            // transfer word1[0:i-1]+C1  to word2[0:j-1]+C2
            // path1  word1[0:i-1]    => word2[0:j-1]  than replace only if C1 != C2
            // path2  word1[0:i-1]+C1 => word2[0:j-1]  than insert C2(step1)
            // path3  word2[0:j-1]+C2 =>  word1[0:i-1] than insert C1(step1)
            // path_min = min(path1, path2, path3)
            temp = (word1[i - 1] == word2[j - 1]) ? dp[i-1][j-1] : (dp[i-1][j-1] + 1);
            temp = MIN(temp, dp[i][j-1] + 1);
            dp[i][j] = MIN(dp[i - 1][j] + 1, temp);       
        }
    }
    ret = dp[row-1][col-1];
    free(dp);
    return ret;
}
```