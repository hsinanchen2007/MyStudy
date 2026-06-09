### 解题思路
之前有用Matlab写过一个围棋的规则，其中围棋棋子的气也是看上下左右四个方向是不是被对方棋子占了。  
如果上下左右四个方向任意一个都有己方棋子，那么就算棋子相连，气也相通；如果被对方棋子占了，这个方向就没有气了。  
当时代码写的老冗长了。  
这个题目有点点类似。还是自己的解法。  
先找出新鲜橘子的个数，用来判断最终能否全部腐烂；  
按轮进行腐烂，为了节省变量，用round来做每轮的计数变量，又来做每轮腐烂橘子的标记；  
主要谁判断四个方向是不是有已经腐烂的（本轮腐烂的不会被算上）。
### 代码

```c

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i, j;
    int fresh_orange = 0, rotten_orange=0; // fresh_orange:新鲜橘子个数; rotten_orange:腐烂的个数
    int round;  // 2:已经腐烂; 3:第一轮腐烂, 4:第二轮腐烂, 5:第三轮腐烂, ...

    // 新鲜橘子个数
    for(i=0; i<gridSize; i++){
        for(j=0; j<gridColSize[i]; j++){
            if(grid[i][j] == 1){
                fresh_orange++;
            }
        }
    }

    // 按轮进行腐烂，第一轮round=3，第二轮round=4，...
    for(round=3; round-3 <= fresh_orange; round++){
        // 判断是否已经全部腐烂
        if(rotten_orange == fresh_orange){
            return round-3;
        }
        // 进行腐烂, 找出将要腐烂的橘子标记为round
        for(i=0; i<gridSize; i++){
            for(j=0; j<gridColSize[i]; j++){
                if(grid[i][j] == 1){
                    // 判断上、下、左、右是否有已经腐烂的橘子
                    if((i-1>=0 && grid[i-1][j]>=2 && grid[i-1][j]<round) || \
                    (i+1<gridSize && grid[i+1][j]>=2 && grid[i+1][j]<round) || \
                    (j-1>=0 && grid[i][j-1]>=2 && grid[i][j-1]<round) || \
                    (j+1<gridColSize[i] && grid[i][j+1]>=2 && grid[i][j+1]<round)){
                        grid[i][j] = round;
                        rotten_orange++;
                    }
                }
            }
        }
    }

    return -1;
}

```