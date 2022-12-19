```java
class Solution {
    public double[] twoSum(int n) {
        // n个骰子的表面值之和 (组合)
        int numsCount = n * 6 - n * 1 + 1;  // 点数和的个数
        //可以用滚动数组优化
        int[][] dp = new int[n+1][n * 6 + 1];
        //初始化第0行为1, 因为dp[i][k + j] = dp[i][k + j] + dp[i-1][k]; 在第一行时需要计算
        Arrays.fill(dp[0],1); 
        for(int i=1;i<=n;i++){ // i: 投掷第i个骰子
            for(int j=1;j<=6;j++){ //j: 第i个骰子投掷得到点数
                for(int k = (i-1)*1;k <= (i - 1)*6;k++){  
                    // k 取值范围：[(i-1)*1,(i-1)*6] 即：前i-1个骰子的点数组合可能得到的点数的范围
                    // k + j : i个骰子的点数组合 = 前i-1个骰子的点数 + 第i个骰子投掷得到的点数j   
                    // dp[i-1][k]：前i-1个骰子的点数组合得到点数k时的可能数
                    // dp[i][k + j] : i个骰子的点数组合为k+j时的可能数
                    dp[i][k + j] = dp[i][k + j] + dp[i-1][k];
                }
            }
        }
        double[] res = new double[n*6 - n * 1 + 1];
        int sum = 0;
        for(int i=0;i<res.length;i++){
            // i + n：因为投掷n个骰子的点数范围:[n*1,n*6],所以需要取一下偏移
            sum +=  dp[n][i + n]; //计算总数
            res[i] = dp[n][i + n];// 保存结果
        }
        for(int i=0;i<res.length;i++){
            // 计算概率
            res[i] = res[i]/sum;
        }
        return res;
    }
} 
```