### 解题思路
经典的动态规划题目，从终点开始递推到起点，每个格子的值为下面那一个和左边那一个格子的值的和

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] res = new int[m][n];
        
        //首先将最后一行和最后一列赋值为1，因为从那些点出发到终点的路径都为1
        
        for (int i = 0; i < n; i++) {
            res[m - 1][i] = 1;
        }
        
        for (int i = 0; i < m; i++) {
            res[i][n-1] = 1;
        }
        
        //然后从下面依次往上面计算结果
        for(int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                res[i][j] = res[i+1][j] + res[i][j+1];
            }
        }

        return res[0][0];
    }
}
```