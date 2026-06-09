### 解题思路
不会BFS的笨办法

### 代码

```c

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    /* 比较笨的方法是每次遍历找到是腐烂橘子，就将上下左右的好橘子传染了，
    如何判断已经传染完了，就是一次传染下来没有新增的烂橘子 */

    int curbad = badnum;
    int lastbad = badnum;
    int time = 0;
    int a;
    do{
         a=0;
         int update =0;
            for(int i=0; i< gridSize; i++) {
                for(int j=0; j< gridColSize[i]; j++) {
                    if(grid[i][j] == 2) {

                    if (i>0){
                        if (grid[i-1][j]==1){
                            grid[i-1][j]=3;
                            a=1;
                        }
                    }
                    if (j>0){
                        if (grid[i][j-1]==1){
                            grid[i][j-1]=3;
                            a=1;
                        }
                    }
                    if (j+1<gridColSize[0]){
                        if (grid[i][j+1]==1){
                            grid[i][j+1]=3;
                            a=1;
                        }
                    }
                    if (i+1<gridSize){
                        if (grid[i+1][j]==1){
                            grid[i+1][j]=3;

                            a=1;
                        }
                    }
                }
             }
            }
        for(int i=0; i< gridSize; i++) {
            for(int j=0; j< gridColSize[i]; j++) {
                if(grid[i][j] == 3){
                    grid[i][j]=2;
                    if(update == 0){
                        time++;
                        update = 1;
                    }
                }
            }
        }
    } while(a==1) ;

    for(int i=0; i< gridSize; i++) {
            for(int j=0; j< gridColSize[i]; j++) {
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }     


    
    return time;
}
```