使用动态规划解决该问题：
定义DP[i][j]表示0~i的数据划分为j组时相等和的集合，j的取值范围为1-4
具体状态转移过程见代码，比较好理解
时间复杂度O(4 * n^2) = O(n ^ 2)
```
// time complexity O(n ^ 2)
class Solution {
    public boolean splitArray(int[] nums) {
        int n = nums.length;
        Set[][] dp = new Set[n][5];
        int sum = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 1; j <= 4; j++){
                dp[i][j] = new HashSet<>();
            }
        }
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            dp[i][1].add(sum);
        }
        for(int i = 2; i < n ; i++){
            for(int j = 2; j <= 4; j++){
                sum = 0;
                for(int k = i; k >= (j - 1) * 2; k--) { //这一步下限简单的写可直接写成 k>= 2
                    sum += nums[k];
                    if(dp[k-2][j - 1].contains(sum)){
                        dp[i][j].add(sum);
                    } 
                }
            }
        }
        return !dp[n-1][4].isEmpty();
    }
}
```