idea来自于https://www.dreamwings.cn/leetcode813/5231.html

状态转移方程和函数表示意义

 dp(i,j,k) = max{ dp(i,s,k-1)+dp(s+1,j,1),  dp(i,j,k)};
 0<=i<=s<j<N;

```java
class Solution {
    public double largestSumOfAverages(int[] nums,int K){
         int N = nums.length;
        // 前缀和
        int[] preSum = new int[N];
        preSum[0]=nums[0];
        for(int i=1;i<N;i++){
            preSum[i]=preSum[i-1]+nums[i];
        }
        // init
        double[][][] dp = new double[N][N][K+1];
        for(int i=0;i<N;i++){
            for (int j=i;j<N;j++){
                dp[i][j][1]=1.0*sum(i,j,preSum)/(j-i+1); // 注意下先*1.0
            }
        }
        for(int k=2;k<=K;k++){ // k从2取,1已在init阶段取过了
            for (int i=0;i<N;i++){
                for(int j=i+k-1;j<N;j++){ // 注意下j的边界
                    for (int s=i;s<j;s++){
                        dp[i][j][k]=Math.max(dp[i][j][k],dp[i][s][k-1]+1.0*sum(s+1,j,preSum)/(j-s));
                    }
                }
            }
        }
        return dp[0][N-1][K];
    }
    public int sum(int x,int y,int[] sum) {
        return x==0?sum[y]:sum[y]-sum[x-1];
    }

}
```
同类的题目还有 87 扰乱字符串和 312 戳气球
区间DP一般套路 参见 https://oi-wiki.org/dp/interval/
注意下 for循环的处理顺序 第一层必须是子问题的长度 不然就不是DP了!!  取值边界需要理解问题的基础上自己琢磨了 我也不太会哈哈  
然后是上下(或者叫左右)区间的边界遍历 以及 分割点 的遍历  