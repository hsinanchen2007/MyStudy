dp[i][j]存着在第i个数字时能达到j的整数的方法数
类似leetcode里的那道抛硬币问题.
但是抛硬币那题的j都是大于0的.这里有小于0的可能性,所以要给每个j+tot
(tot是数组所有元素和)

```
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        //动态规划
        //dp存着在第i个数字时能达到j的整数的方法数
        //dp遍历完所有数字之后
        //return dp[n][S]即可
        if(nums.length==1){
            if(S==nums[0]||S==-nums[0])
                return 1;
            return 0;
        }
        int tot=0;
        for(int i=0;i<nums.length;i++){
            tot+=nums[i];
        }
         if(S>tot||S<-tot){
            return 0;
        }
        int dp[][]=new int[nums.length+1][2*tot+1];
        dp[1][nums[0]+tot]+=1;
        dp[1][-nums[0]+tot]+=1;
        
        //j大于tot的为正数,小于一千的为负数.
        //这样写是因为sum可能为0,而j表示sum,j不能为负数
        //所以统一加上tot
        //所以return dp[n][S+tot]
        for(int i=2;i<=nums.length;i++){
            int sum=0;
            for(int m=1;m<=i;m++){
                sum+=nums[m-1];
            }//计算一下数组和最大是多少,因为j不可能比这个数字更大
            for(int j=tot-sum;j<=tot+sum;j++){
                if((j-nums[i-1]>=0 )&&(j-nums[i-1]<=2*tot))
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                if((j+nums[i-1]<=2*tot) &&(j+nums[i-1]>=0))
                    dp[i][j]+=dp[i-1][j+nums[i-1]];
            }
        }
        return dp[nums.length][S+tot];
    }
}
```
