1.状态定义dp[i][j]
2.递推公式，同各位大佬
3.状态压缩，本题解旨在给出一个一维数组的优化方法，思想和高赞题解各位完全一致
```
class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int[] dp = new int[n2 + 1];
        // dp[0][0...n2]的初始值
        for (int j = 1; j <= n2; j++) 
            dp[j] = j;
        // 通过公式推出 dp[n1][n2]
        for (int i = 1; i <= n1; i++) {
            int temp = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n2; j++) {
                int pre = temp;
                temp = dp[j];
                // 如果 word1[i] 与 word2[j] 相等。第 i 个字符对应下标是 i-1
                if (word1.charAt(i - 1) == word2.charAt(j - 1)){
                    dp[j] = pre;
                }else {
                    dp[j] = Math.min(Math.min(pre, dp[j - 1]), dp[j]) + 1;
                }         
            }
        }
        return dp[n2]; 
    }
}
```
