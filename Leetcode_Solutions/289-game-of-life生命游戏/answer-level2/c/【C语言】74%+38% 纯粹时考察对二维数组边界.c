### 解题思路
1.思路比较简单：思路其实很简单，就照着生命游戏的规则往下写就行。
2.corner condition：
（1）.在用if else实现时，第三条定律的优先级优于第二条；
（2）.对二维数组的i,j操作时，对边界条件的检查；
3.知识点总结：
无。
4.耗时：40mins，有点长。主要耗时点：
（1）live计算时，对i和j的边界的计算，编码时比较小心谨慎，花的时间比较长-----编码熟练度；
![image.png](https://pic.leetcode-cn.com/62b44b124494691ade81f2c47e58875626bea59deb290eb0b44e246003c45fe4-image.png)


### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int i = 0;
    int j = 0;
    int live = 0;
    int **temp = NULL;
    temp = (int **)malloc(boardSize * sizeof(int *));
    for(i = 0 ;i < boardSize; i++) {
        temp[i] = (int *)malloc((*boardColSize) * sizeof(int));
        memset(temp[i], 0x00, (*boardColSize) * sizeof(int));
    }

    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < *boardColSize; j++) {
            live = 0;
            if((0 <= i - 1)  && (0 <= j - 1) && board[i - 1][j - 1] == 1) {
                live++;
            }
            if((0 <= i - 1)  && board[i - 1][j] == 1) {
                live++;
            }   
            if((0 <= j - 1)  && board[i][j - 1] == 1) {
                live++;
            }    
            if(( i + 1 < boardSize)  && (j + 1 < *boardColSize) && board[i + 1][j + 1] == 1) {
                live++;
            }
            if(( i + 1 < boardSize) && board[i + 1][j] == 1) {
                live++;
            }  
            if((j + 1 < *boardColSize) && board[i][j + 1] == 1) {
                live++;
            }                      
            if((0 <= i - 1) && (j + 1 < *boardColSize) && board[i - 1][j + 1] == 1) {
                live++;
            }   
            if(( i + 1 < boardSize) && (0 <= j - 1) && board[i + 1][j - 1] == 1) {
                live++;
            }  

            if(live < 2) {
                temp[i][j] = 0;
            }
            else if (3 < live) {
                temp[i][j] = 0;
            }            
            else if (board[i][j] == 1 && (2 <= live || live <= 3)) {
                temp[i][j] = 1;
            }
            else if(board[i][j] == 0 && live == 3) {
                temp[i][j] = 1;
            }
        }
    }

    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < *boardColSize; j++) {
            board[i][j] = temp[i][j];
        }
    }
    for(i = 0; i < boardSize; i++) {
        free(temp[i]);
        temp[i] = NULL;
    }
    free(temp);
    return;
}
```