# 首先只考虑垂直方向重叠
    - 如果是垂直方向上重叠的话，假如有N(N>0)个立方体，那么面积应该是4N+2;
    - 当N=0时，自然是0
# 考虑与上方（即行与行之间）的重叠
    重叠部分的面积应该是两者之间面积较小的那一个面积的两倍
# 考虑与左方（即列与列之间）的重叠
    重叠面积计算方法同上
代码如下
```
int min(a,b){
    return a>b?b:a;
}
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int count = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(grid[i][j]==0)
                continue;
            count+=4*grid[i][j]+2;
            //如果不是第一行，减去和上一行两者之间小的那个*2
            if(i!=0)
                count-=(2*min(grid[i-1][j],grid[i][j]));
            //如果不是第一列，减去和左一列两者之间小的那个*2   
            if(j!=0)
                count-=2*min(grid[i][j-1],grid[i][j]);
        }
    }
    return count;
}
```
