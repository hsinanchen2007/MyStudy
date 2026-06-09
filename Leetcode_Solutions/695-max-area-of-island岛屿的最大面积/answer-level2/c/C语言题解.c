### 解题思路
岛屿最大面积，以前在《啊哈！算法》一书中的第四章里面遇到过这类题目，很经典的题目，要求最大的岛屿面积，我们遍历数组中的元素，当为1时，表明当前为陆地，将其置为-1，防止重复计算，并且从当前位置继续漫水填充，也就是对于当前位置上下左右四个方向的陆地进行感染，每一个被感染的位置又可以继续感染其他陆地，直到无法感染为止。接着将获得的岛屿面积与当前最大岛屿面积进行比较替换即可，代码挺清晰的，也可以直接看代码

### 代码

```c
int check(int x,int y,int** grid,int gridSize,int* gridColSize){
    int next_step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int i;
    int sum=1;
    for(i=0;i<4;i++){
        int next_x=x+next_step[i][0];
        int next_y=y+next_step[i][1];
        if(next_x>=0&&next_x<gridSize&&next_y>=0&&next_y<gridColSize[x]&&grid[next_x][next_y]==1){
            grid[next_x][next_y]=-1;
            sum+=check(next_x,next_y,grid,gridSize,gridColSize);
        }
    }
    return sum;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i,j,num=0,sum=0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1){
                grid[i][j]=-1;
                num=check(i,j,grid,gridSize,gridColSize);
                if(num>sum){
                    sum=num;
                }
            }
        }
    }
    return sum;
}
```