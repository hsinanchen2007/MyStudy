
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char g_out[1000][1000][100] = {0};
char tmpRecord[1000][100] = {0};
/* 判断字符串是否为回文 */
int judge(char *input, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (input[i] != input[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

/* 用DFS记录所有回文串 */
void DFS(char *s, int *row, int *col, int recordCol) {
    int len = strlen(s);  
    for (int i = len; i >= 1; i--) {
        int tmpC = recordCol;
        if (judge(s, i)) {
            memset(tmpRecord[tmpC], 0, sizeof(tmpRecord[tmpC]));
            memcpy(tmpRecord[tmpC], s, i * sizeof(char));
            tmpRecord[tmpC][i] = '\0';
            tmpC++;
            if (i == len) {
                for (int j = 0; j <tmpC; j++) {
                    int sLen = strlen(tmpRecord[j]);
                    memcpy(g_out[*row][j], tmpRecord[j], sLen + 1);                    
                }
                col[*row] = tmpC;
                (*row)++;
                continue;
            }
            char *tmpS;
            tmpS = s + i;

            DFS(tmpS, row, col, tmpC);            
        }
    }
}
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    int row = 0;
    int col[1000] = {0};
    DFS(s, &row, col, 0);
    *returnSize = row;
    returnColumnSizes[0] = (int *)malloc(row * sizeof(int));
    
    char ***output;
    output = (char ***)malloc(row * sizeof(char **));
    
    for (int i = 0; i < row; i++) {
        returnColumnSizes[0][i] = col[i];
        int colNum = col[i];
        output[i] = (char **)malloc(colNum * sizeof(char *));
        for (int j = 0; j < colNum; j++) {
            output[i][j] = g_out[i][j];
        }
        
    }
    return output;
}


```
