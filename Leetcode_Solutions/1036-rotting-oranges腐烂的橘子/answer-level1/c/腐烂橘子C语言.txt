### 解题思路
难点有如下几个, 一一排除:

* 传参, 第三个参数一时难以理解, 结果是每行个数
* 考虑到某个橘子周围感染后将会被再次扫描到, 所以将其置为3, 最后在统一变成2即可(没学过BSF自己脑补的)
* 关于次数, 每次都需要记录一下次轮是否有新的橘子被感染, 没有则停止
* 还需优化, 不一定grid正好是矩形

### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int timeCount = 0;
    int mark = 0;
    do{
        mark = 0;
        for(i=0;i<gridSize;i++){
            for(j=0;j<gridColSize[i];j++){
                if(grid[i][j]==2){
                    if(i-1>=0 && grid[i-1][j]==1) //上
                    {
                        grid[i-1][j] = 3;
                        mark = 1;
                    }
                    if(j-1>=0 && grid[i][j-1]==1)//左
                    {
                        grid[i][j-1] = 3;
                        mark = 1;
                    }
                    if(i+1<gridSize && grid[i+1][j]==1){//下
                        grid[i+1][j] = 3;
                        mark = 1;
                    }
                    if(j+1<gridColSize[i] && grid[i][j+1]==1){//右
                        grid[i][j+1] = 3;
                        mark = 1;
                    }
                }
            }
        }

        for(i=0;i<gridSize;i++){
            for(j=0;j<gridColSize[i];j++){
                if(grid[i][j]==3)
                    grid[i][j] = 2;
            }
        }
        timeCount++;
    }while(mark==1);

    for(i=0;i<gridSize;i++){//检查是否有橘子不可能被感染
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1)
                return -1;
        }
    }

    return timeCount-1;//因为do while会多跑一次
}


```