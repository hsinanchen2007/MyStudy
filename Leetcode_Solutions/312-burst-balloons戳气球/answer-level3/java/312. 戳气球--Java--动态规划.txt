[Leetcode-Java(更多题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_312_maxCoins.java)

```java
    /**
     * 解题思路：如何使最终结果最大化？动态规划保存结果
     * 1.将问题拆解成求i->j的最大值，最大的i=0,j=n
     * 2.从i->j中找一个k，拆分求解，i->k,k,k->j三个值之和的最大值
     * 3.i->k和k->j代表k的左边和右边全部戳破求解的最大值
     * 4.左右全部戳破后，k的值为num[i]*num[k]*num[j]
     * 5.动态转移方程：dp[i][j]=Math.max(dp[i][j],dp[i][k]+dp[k][j]+num[i]*num[k]*num[j]);
     *
     * @param nums
     * @return
     */
    public int maxCoins(int[] nums) {
        //dp[i][j]代表i->j的最大值
        int[][] dp = new int[nums.length + 2][nums.length + 2];
        //左右+1方便操作。 nums[-1] = nums[n] = 1
        int[] newNums = new int[nums.length + 2];
        for (int i = 1; i < newNums.length - 1; i++) {
            newNums[i] = nums[i - 1];
        }
        newNums[0] = 1;
        newNums[newNums.length - 1] = 1;
        //从2开始，保证最少3个
        for (int j = 2; j < newNums.length; j++) {
            //遍历所有的可能性，0-2...0-n,1-3...1-n,...
            for (int i = 0; i < newNums.length - j; i++) {
                for (int k = i + 1; k < i + j; k++) {
                    dp[i][i + j] = Math.max(dp[i][i + j], dp[i][k] + dp[k][i + j] + newNums[i] * newNums[k] * newNums[i + j]);
                }
            }
        }
        return dp[0][newNums.length - 1];
    }
```