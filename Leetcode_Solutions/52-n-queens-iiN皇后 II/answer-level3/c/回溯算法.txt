### 解题思路
逐行进行回溯即可。

### 代码

```c

#include <stdio.h>
#include <stdlib.h>
/* 算法思想 第一行，第1,2,3,4，。。。n列尝试放入一个
*/
int checkCurRow(int totalRow, int curRow, int col, int *result)
{
    //检查col是否满足要求,result中存放的是每个行中的col值，当前的col值不能与之冲突。
    for(int i = 0; i < curRow; i++) {
        if(result[i] == col)
        {
            return 1;  //同列
        }
    }

    //校验是否同对角线
    int tmpRow,tmpCol;
    tmpRow = curRow;
    tmpCol = col;
    while(tmpRow > 0 && tmpCol > 0) {
        tmpRow = tmpRow - 1;
        tmpCol = tmpCol - 1;
        if(result[tmpRow] == tmpCol) {
            return 1;
        }
    }
    tmpRow = curRow;
    tmpCol = col;
    while(tmpRow > 0 && tmpCol < totalRow-1) {
        tmpRow = tmpRow - 1;
        tmpCol = tmpCol + 1;
        if(result[tmpRow] == tmpCol) {
            return 1;
        }
    }
    tmpRow = curRow;
    tmpCol = col;
    while(tmpRow < totalRow-1 && tmpCol > 0) {
        tmpRow = tmpRow + 1;
        tmpCol = tmpCol - 1;
        if(result[tmpRow] == tmpCol) {
            return 1;
        }
    }
    tmpRow = curRow;
    tmpCol = col;
    while(tmpRow < totalRow-1 && tmpCol < totalRow-1) {
        tmpRow = tmpRow + 1;
        tmpCol = tmpCol + 1;
        if(result[tmpRow] == tmpCol) {
            return 1;
        }
    }
    return 0;
}


int total = 0;
void queuedfs(int totalRow, int curRow, int *result){
    if(curRow == totalRow) {
        total++;
      //  for(int i = 0; i < 4; i++) {
        //    printf("%d ", result[i]);
       // }
       // printf("\r\n");
        return;
    }

    for(int col = 0;  col < totalRow ; col++) {
        if(curRow == 0) {
            result[curRow] = col;
            queuedfs(totalRow, curRow+1, result);
            result[curRow] = -1;
        }
        else if(curRow > 0) {
            if(checkCurRow(totalRow, curRow, col, result) == 1) {
                continue;
            }
            result[curRow] = col;
            queuedfs(totalRow, curRow+1, result);
            result[curRow] = -1;

        }
    }

}
int totalNQueens(int n){
    total = 0;
    int visit[n];
    int board[n][n];
    int result[n];  //每行的列值，注意要每列都不能相同。
    for(int i = 0; i < n; i++) {
        result[i] = -1;
        for( int j = 0 ; j < n ; j++) {
            board[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        visit[i] = 0;
    }
    queuedfs(n,0, result);
    //printf(" %d " , total);
    return total;
}
```