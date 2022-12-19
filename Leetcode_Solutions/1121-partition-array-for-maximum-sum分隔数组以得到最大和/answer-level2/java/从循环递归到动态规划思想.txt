这个问题最直观的想法是把每个组合可能都遍历一边，从中找到最优解。
```
//用递归循环的方式
    public int maxSumAfterPartitioning1(int[] A, int K) {
        return maxSum(A,0,K);
    }
    public int maxSum(int[] A, int index, int K) {
        int maxVal=0;
        //表示以i个数字为一组
        int i=0;
        int maxSum=0;
        for(i=0;i<K&&index+i<A.length;i++){
            maxVal=Math.max(A[index+i],maxVal);
            maxSum=Math.max(maxSum,maxVal*(i+1)+maxSum(A,index+i+1,K));
        }
        return maxSum;
    }
```

但是从代码中可以看到，在递归过程中很多遍历过程都重复了，造成超时。
于是想到是否可以把底层递归遍历过的结果保存下来，进一步想到，动态规划
其实就是对这种问题的一种优化解法。
以上从循环递归——保存循环——动态规划的思路，是很多动态规划问题的思考
方式。

动态规划的思路其实就是
dp[i]代表从i到最后的所有数字组合的最大和，向前遍历，增加一个数字A[i-1].
那么dp[i-1]最优解可能是
- A[i-1]单独做一组，加上dp[i]
- 从后面拿一个{A[i-1],A[i]}组成一组，加上dp[i+1]
- 从后面拿两个...
- 最多从后面拿k-1个，加上剩下的dp[i-k+1]
```
 //用动态规划的方式
    public static int maxSumAfterPartitioning(int[] A, int K) {
         int len=A.length;
         int[]dp=new int[len+1];
         dp[len-1]=A[len-1];
         int maxVal=0;
         int maxSum=0;
         for(int i=len-2;i>=0;i--){
             maxVal=A[i];
             maxSum=A[i]+dp[i+1];
             for(int j=1;j<K&&i+j<len;j++){
                 maxVal=Math.max(maxVal,A[i+j]);
                 maxSum=Math.max(maxSum,maxVal*(j+1)+dp[i+j+1]);
             }
             dp[i]=maxSum;

         }
         return dp[0];
    }
```

