
如果直接套用之前机器人走路的思路，可以做到O(n^3)
因为这里只有三种颜色，可以做到O(n)
如果是N种颜色，就只能是O(n^3)
![image.png](https://pic.leetcode-cn.com/8d2dc074de7dbd0a4c5829a3fdf9f6fee963cb5241799963f7c9502bde79beb1-image.png)

还是用机器人走路的二维dp
这里可以in-place，即使用原来的costs作为dp矩阵
输入[
[17,2,17],
[16,16,5],
[14,3,19]
]
第一行[17, 2, 17]为dp初始状态
第二行开始进行状态转移方程：dp[i][j] = Min(dp[i-1]) + dp[i][j]
含义：在对第i座房子，涂第j种颜色时，第i-1座房子就不能涂成第j种颜色，
因而，就找第i-1行的最小值（最小花费），
加上当前对第i座房子，涂第j种颜色时的花费。

最终的dp矩阵
17 2 17
18 33 7
21 10 37

遍历最后一行，得到最小花费10

```
class Solution {
    public int minCost(int[][] costs) {
        if( costs.length == 0 ) {
            return 0;
        }
        for( int i = 1; i < costs.length; i++ ) { 
            for( int j = 0; j < costs[0].length; j++ ) {
                // For every row[i], find the minimum of row[i-1], excluding the element costs[i-1][j]
                int minCost = findMin(costs[i-1], j);
                costs[i][j] += minCost;               
            }                        
        }
        
        int ans = Integer.MAX_VALUE;
        int N = costs.length - 1;
        int colors = costs[0].length;
        for( int j = 0; j < colors; j++ ) {
            if( costs[N][j] < ans ) {
                ans = costs[N][j];
            }
        }      
        return ans;
    }
    
    private int findMin(int[] cost, int index) {
        
        int minCost = Integer.MAX_VALUE;
        for( int i = 0; i < cost.length; i++ ) {
            if( i != index && cost[i] < minCost ) {
                minCost = cost[i];
            }
        }
        return minCost;
        
    }
    
}
```
时间复杂度O(N^3), 房子数量N, 颜色数量N, 转移方程代价N(从N-1个数中找到最小值)
空间复杂度O(1)