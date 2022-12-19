// 原理参考 花花酱   https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1000-minimum-cost-to-merge-stones/

//  难点主要在于区间DP的状态转移不是一步到位的,第二个状态转移方程式需要懂哦  区间DP问题特点 是for循环第一层 是子问题的长度 所以是for len =2 len < N;len++

    // leetcode 1000  合并石头的最低成本
    // 0<=i<=t<j<N  1<=k<=K
    // 有2次状态转移
    // dp(i,j,k) = min(dp(i,j,k),dp(i,t,k-1)+dp(t+1,j,1))
    //dp(i,j,1) = min(dp(i,j,K)+prefixSUM[i:j]

```java
class Solution {
    public int mergeStones(int[] stones, int K) {
        int N = stones.length;
        if((N-1)%(K-1)!=0) return -1;// 是否有解的前提条件
        //前缀和
        int[] preSum = new int[N];
        preSum[0]=stones[0];
        for(int i=1;i<N;i++){
            preSum[i]=preSum[i-1]+stones[i];
        }
        int[][][] dp = new int[N][N][K+1]; //k能取到K 因故是K+1
        for (int i=0;i<dp.length;i++){
            for (int j=0;j<dp[i].length;j++){
                for (int k=0;k<dp[i][j].length;k++){
                    dp[i][j][k]=Integer.MAX_VALUE; // 必须初始化为MAX_VALUE 如果是0 min取值 
 // 如果可以取到0 ,偏离这道题目的 动态规划本意了  , 初始化MAX_VALUE代表 有解前提下,取到dp(i,j,1)的最小成本
                }
            }
        }
        // init
        for(int i=0;i<N;i++){
            dp[i][i][1]=0;// 注意是0哦
        }
        for(int len =2;len <= N; len++){ // sub problem length
            for(int i=0;i<=N-len;i++){
                int j = i+len-1;
                for(int k=2;k<=K;k++){
                    for(int m=i;m<j;m +=K-1){ // m 跳步应该是k-1
                        dp[i][j][k]=Math.min(dp[i][j][k],dp[i][m][1]+dp[m+1][j][k-1]);
                        dp[i][j][1]=sum(i,j,preSum)+dp[i][j][k];
                    }
                }
            }
        }
        return dp[0][N-1][1];
    }
    
    /**
     * @param x inclusive
     * @param y inclusive
     * @param preSum prefix sum for arr[0:N-1]
     * @return sum of arr[x:y]
     */
    public int sum(int x,int y,int[] preSum) {
        return x==0?preSum[y]:preSum[y]-preSum[x-1];
    }
}
```