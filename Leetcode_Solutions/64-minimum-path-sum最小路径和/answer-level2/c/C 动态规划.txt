### 解题思路
动态规划，进行了些内存优化，只用一个数组记录上一行的结果
但写得较烂..就这样吧。。

### 代码

```c
#define MIN(a,b) ((a)<(b)?(a):(b))
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int *arr = (int *)malloc(sizeof(int) *gridColSize[0]);
    arr[0] = 0;
    
    int j,k;
    for(j=0;j<gridSize;j++){
        for(k=0;k<gridColSize[j];k++){
            if(k==0) arr[k] += grid[j][k];
            else if(j==0) arr[k] = arr[k-1] + grid[j][k];
            else arr[k] = MIN(arr[k],arr[k-1]) + grid[j][k];
        }
    }
    return arr[k-1];
}
```