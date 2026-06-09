### 解题思路
题意为：
[[2]]表示0行0列上放两个立方体，表面积为12减去上下重叠的面积2；
[[1,2],[3,4]]表示0行0列上放一个立方体，0行1列上放2个立方体，1行0列上放3个立方体，1行1列上放4个立方体
读懂题意之后，可以得知并行并列上下重叠会导致表面积减去2
然后依次处理并行并列上下重叠情况。

### 代码

```c
#define MIN(a,b) (a>b?b:a)
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j,sum=0;
    if(gridSize==0||*gridColSize==0) return 0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<*gridColSize;j++){
            sum=sum+6*grid[i][j];
            if(i!=gridSize-1){//处理并列重叠
                sum=sum-2*MIN(grid[i][j],grid[i+1][j]);//前一行与后一行重叠 1,3重叠1。2,3重叠2
            }
            if(j!=*gridColSize-1){//处理并行重叠
                sum=sum-2*MIN(grid[i][j],grid[i][j+1]);//前一列与后一列重叠 1,3重叠1。2,3重叠2
            }
            if(grid[i][j]>1){//处理上下重叠 
                sum=sum-2*(grid[i][j]-1);//2层重叠2-1层,3层重叠3-1层  
            }         
        }
    }
    return sum;
}
```