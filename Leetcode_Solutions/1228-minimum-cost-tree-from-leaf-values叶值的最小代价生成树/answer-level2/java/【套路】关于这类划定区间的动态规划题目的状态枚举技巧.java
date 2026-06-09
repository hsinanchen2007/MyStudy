这类划定区间的动态规划题目，状态枚举是有**技巧**的！而且掌握了这种状态枚举的**套路**，你会发现在LeetCode的一些动态规划题目都能用到！  
比如：312.戳气球也能用到这种状态枚举技巧。  

这道题的动态规划解法不难：  
定义：dp[i][j][0]为i到j的arr最大值，dp[i][j][1]为i到j的能组成的树的最小代价;  
初始状态：dp[i][i][0] = arr[i], dp[i][i][1] = 0;  
状态转移方程:dp[i][j][1] = min{dp[i][k][1] + dp[k + 1][j][1] + dp[i][k][0] * dp[k + 1][j][0]}, i =< k < j;   

两种**枚举技巧**分别是**固定区间长度**和**固定一端**：  
```java
    public int mctFromLeafValues(int[] arr){
        int len;
        if(arr == null || (len = arr.length) == 0)return 0;
        int[][][] dp = new int[len][len][2];

        // 初始状态.
        for(int i = 0; i < len; ++i){
            dp[i][i][0] = arr[i];
        }

        // 固定一端式，典型的O(n3)时间复杂度的算法
        for(int i = 1; i < len; ++i){
            for(int j = i - 1; j >= 0; --j){
                dp[j][i][1] = Integer.MAX_VALUE;
                int tmp;
                for(int k = j; k < i; ++k){
                    if((tmp = dp[j][k][1] + dp[k + 1][i][1] + dp[j][k][0] * dp[k + 1][i][0]) < dp[j][i][1]){
                        dp[j][i][1] = tmp;
                        dp[j][i][0] = Math.max(dp[j][k][0], dp[k + 1][i][0]);
                    }
                }
            }
        }

        // 固定区间长度
        // for(int k = 2; k <= len; ++k){
        //     for(int i = 0; i + k - 1 < len; ++i){
        //         int j = i + k - 1, p, tmp;
        //         dp[i][j][1] = Integer.MAX_VALUE;
        //         for(p = i; p < j; ++p){
        //             if((tmp = dp[i][p][1] + dp[p+1][j][1] + dp[i][p][0] * dp[p+1][j][0]) < dp[i][j][1]){
        //                 dp[i][j][1] = tmp;
        //                 dp[i][j][0] = Math.max(dp[i][p][0], dp[p+1][j][0]);
        //             }
        //         }
        //     }
        // }
        return dp[0][len - 1][1];
    }
```
也可以看这里：[关于动态规划的一点简单思考](https://qinstaunch.github.io/2019/12/17/%E5%85%B3%E4%BA%8E%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%9A%84%E4%B8%80%E7%82%B9%E7%AE%80%E5%8D%95%E6%80%9D%E8%80%83/)