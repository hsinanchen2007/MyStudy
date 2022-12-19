由于每个骰子最小为1点，且必须用到每一个骰子，实际上可以将target-d,题目就变为01背包，每个骰子的值为0至f-1
```
class Solution {
    public int numRollsToTarget(int d, int f, int target) {
        if(target < d || target > d*f) return 0;
        target -= d;
        int[] dp = new int[target+1];
        int mod = 1000000007;
        dp[0] = 1;
        for(int i = 1 ; i <= d ; i++){
            for(int j = target ; j >= 0 ; j--){
                for(int k = 1 ; k < f; k++){
                    if(j >= k){
                        dp[j] += dp[j-k];
                        dp[j] %= mod; 
                    }
                }
            }
        }
        return dp[target];
    }
}
```
