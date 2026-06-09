### 解题思路
首先要了解题目意思 ==

说一下 [[1,2],[3,4]] = 34

[1,2] 代表 0,0位置放置1块，0,1位置放置2块
[3,4] 代表 1,0位置放置3块，1,1位置放置4块

现在可以画一个草图：

我们每一块都考虑左面\下面\前面

说白了就是左面\下面\前面有没有邻居，若有则减去2(这里2的意思2*1)


### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int res = 0;
    int tmp;
    for(i = 0; i < gridSize;i++) {
        for(j=0;j< * gridColSize;j++) {
            if(grid[i][j]!=0) {
                res += 6 * grid[i][j];
                res = res - 2*(grid[i][j]-1); // 下面 
                // 比如3块摞在一起，则其中有2个夹层，则减去2*(3-1)
                
                if(i>0){  // 左面  若有左邻居，则减去双方较矮的面*2
                    tmp = grid[i-1][j]>grid[i][j]? grid[i][j]:grid[i-1][j];
                    res = res - 2*tmp;
                }
                
                if(j>0){ // 前面 若有前邻居，则减去双方较矮的面*2
                    tmp = grid[i][j-1]>grid[i][j]? grid[i][j]:grid[i][j-1];
                    res = res - 2*tmp;
                }             
            }
        }
            
    }
    return res;
}
```