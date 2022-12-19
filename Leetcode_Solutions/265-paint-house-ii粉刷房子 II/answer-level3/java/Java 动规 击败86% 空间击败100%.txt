
    这是Leetcode256的推广

    可以用简单思路，但是还有更好的优化，此解是通用思路，但时间复杂度是败笔。

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
    遍历最后一行，得到最小值10


![image.png](https://pic.leetcode-cn.com/b12d49eb2e88fb48f486c829b5750a98e4c18e27c4c1726b68222c45470d704d-image.png)
![image.png](https://pic.leetcode-cn.com/cbd560136f5c31b1b0374c946d51ec49058c8f26aaed5da82f998f06f038698a-image.png)

```
class Solution {
    public int minCostII(int[][] costs) {
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

时间复杂度O(N*k*N)
空间复杂度O(1)