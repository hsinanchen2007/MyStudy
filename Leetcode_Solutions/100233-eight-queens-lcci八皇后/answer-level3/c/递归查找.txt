### 解题思路
递归查找，记录中间过程，不满足则回溯，关键思路见注释，初始化的时候取了个巧，假设N个皇后最多N*100个解
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool findNQueensPos(int n, int* size, int* queenPos, int index, char*** retQuePos)
{
    bool findPos = true;
    char **out = NULL;
    int debug = 0;
    if (index > n) { //找到符合的值，格式化输出
        out = (char**)malloc(n * sizeof(char*));
        if(debug) printf("\nwondful match %d::: \n",*size+1);
        for (int i = 0; i < n; i++) {
           if(debug) printf("%d ",queenPos[i+1]);
            out[i] = (char*) malloc((n+1) * sizeof(char));
            memset(out[i], 0, (n+1) * sizeof(char));
        }
        for (int y = 0; y < n; y++){
           if(debug) printf("\n");
            for (int x = 0; x < n; x++) {
                if(queenPos[y+1] == (x + 1)) {
                    out[x][y] = 'Q';
                } else {
                    out[x][y] = '.';
                }
              if(debug)  printf("%c ",out[x][y]);
            }
        }
        retQuePos[*size] = out; // 位置放到输出链上
        (*size)++;
        return true;
    }

    for (int i = 1; i <= n; i++) {        // 给第index皇后找位置,从第一个位置开始匹配
        findPos = true;
        for (int j = 1; j < index; j++) { // 检查index皇后是否可以放在i这个位置
            if (queenPos[j] == i || (abs(index - j) == abs(i - queenPos[j]))){
                findPos = false;
                break;
            }
        }
        if(debug)printf("find %c? for %d queen pos is %d\n",findPos?'Y':'N',index,i);
        if (findPos == true) {            
            queenPos[index] = i;// 找到占坑
            index++;
            if(debug)printf("====:find for the next:%d\n",index);
            findPos = findNQueensPos(n, size, queenPos, index, retQuePos); 
            if(debug)printf("====:roll back\n");
            index--; // 用完退坑
            queenPos[index] = 0;
            
        }     
    }
    return findPos;
}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    int *tmpQuePos = NULL;
    char ***retQuePos = NULL;
    int index = 1;

    if (n < 1) {
        return NULL;
    }
    *returnSize = 0;
    tmpQuePos = (int *) malloc((n+1) * sizeof(int));
    memset(tmpQuePos, 0, (n+1) * sizeof(int));   
    retQuePos = (char***) malloc(100*n*sizeof(char**));
    memset(retQuePos, 0, 100*n*sizeof(char**));

    (void)findNQueensPos(n, returnSize, tmpQuePos, index, retQuePos);
    (*returnColumnSizes) = (int*)malloc((100*n) * sizeof(int));
    for (int i = 0; i < 100*n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    free(tmpQuePos);
    return retQuePos;
}
```