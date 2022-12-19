### 解题思路
这道题，每一态都与前一态有线性关系，可以用线性规划的思想求解，整体思路是：没走一步，记录下走到这里的最小距离，由于每一点都有两种到达途径(除去端点),所以也有两种动态方程，是一种动态方程组的形式。
    当grid[i][j-1]>grid[i-1][j]时，grid[i][j]=grid[i][j]+grid[i-1][j]
    当grid[i][j-1]<grid[i-1][j]时，grid[i][j]=grid[i][j]+grid[i][j-1]
也就是说，grid[i][j]的值永远等于上一步中的小值。

算法思路：
1. 初始条件第一行和第一列可以直接求得，利用上一步的值加上此步的值
2. 开始动态规划，利用上面给出的动态规划方程

### 代码

```golang
func minPathSum(grid [][]int) int {
    if len(grid)<=0{
        return 0
    }

    row:=len(grid)
    col:=len(grid[0])
    //1.初始条件
    for i:=1;i<col;i++{
        grid[0][i]=grid[0][i-1]+grid[0][i]
    }
    for i:=1;i<row;i++{
        grid[i][0]=grid[i-1][0]+grid[i][0]
    }
    //2.开启动态规划
    for i:=1;i<row;i++{
        for j:=1;j<col;j++{
            if grid[i-1][j]>grid[i][j-1]{
                grid[i][j]=grid[i][j-1]+grid[i][j]
            }else{
                grid[i][j]=grid[i-1][j]+grid[i][j]
            }
        }
    }
    
    return grid[row-1][col-1]
}
```