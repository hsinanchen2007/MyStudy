执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :34.3 MB, 在所有 java 提交中击败了89.13%的用户
```
class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        if(days == null || days.length < 1 || costs == null || costs.length < 1)
            return 0;
        int[] dp = new int[days[days.length-1]+1];
        for(int num : days){
            dp[num] = Integer.MAX_VALUE;
        }
        for(int i = 1; i <= dp.length-1; i++){
            if(dp[i] == 0){
                dp[i] = dp[i-1];
                continue;
            }
            int num1 = dp[i-1]+costs[0];
            int num2 = i > 7 ? dp[i-7]+costs[1] : costs[1];
            int num3 = i > 30 ? dp[i-30]+costs[2] : costs[2];
            dp[i] = Math.min(num1,Math.min(num2,num3));
        }
        return dp[dp.length-1];
    }
}
```
