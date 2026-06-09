### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/28e7a276af6457411e28adb060aa39a1c394eb1c11aa7c9ccf5814e71fd7fc1d-image.png)

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
            //首先知道这是一个遍历问题，正反向遍历都可以，这里是从后往前遍历。
            //怎样从后往前遍历，动态规划分阶段
            //第一阶段： 最后一步即 n 步，肯定是 f[m][n]
            //第二阶段： n-1 步， f[m][n] 到 f[m-1][n], f[m][n-1]
            //以此类推，考虑边界问题，即往回推只有一种方法， 如 某个阶段 f[x][y] 只能退到 f[x-1][y] 或者 f[x][y-1]
            //边界情况，最后，当 x=0, y=0 时，停止退回。
            //状态：每一个 f[m][n]表示从当前开始最大的价值，其实每步的状态只需要参考最终的状态即可，比如，我们回退其实是为了到达本来的起点 f[0][0], 那么 f[0][0]要求的是从 f[0][0]开始的最大价值，所以从最后一步到起点 f[0][0]的过程每个状态也应该为从当前状态开始到终点的最大价值。
            //由上面可以看出，每一步的最大价值等于min{ f[m+1][n] , f[m][n+1]} + f[m][n];    
            //开始做题
        int m = grid.length-1; int i ; // 行边界
        int n = grid[0].length-1; int j; // 列边界
        for(i=m;i>=0;i--){
            for(j=n;j>=0;j--){
                if(j==n&&i==m) continue; //终点是界限，无需改变。
                if(j==n) {grid[i][j]=grid[i][j]+grid[i+1][j];}
                else if(i==m) {grid[i][j]=grid[i][j]+grid[i][j+1];}
                else grid[i][j]=grid[i][j]+Math.max(grid[i+1][j],grid[i][j+1]);
        }
    }
    return grid[0][0];
}
}
```