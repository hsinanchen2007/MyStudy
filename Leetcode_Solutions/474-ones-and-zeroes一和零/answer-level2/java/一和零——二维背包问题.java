稍微转变一下题意：对于数组中的每一个字符串，其中包含的0的个数为代价 $c_1$，其代价上限为m；包含的1的个数为代价 $c_2$，其代价上限为n。典型的二维费用背包问题。这里笔者直接给出代码：
```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        int[] cm = new int[strs.length], cn = new int[strs.length];
        for (int i = 0; i < strs.length; i++) {
            int zeros = getZeros(strs[i]);
            cm[i] = zeros;
            cn[i] = strs[i].length() - zeros;
        }
        for (int i = 0; i < strs.length; i++) {
            for (int j = m; j >= cm[i]; j--) {
                for (int k = n; k >= cn[i]; k--) {
                    dp[j][k] = Math.max(dp[j][k], dp[j - cm[i]][k - cn[i]] + 1);
                }
            }
        }
        return dp[m][n];
    }

    public int getZeros(String s) {
        int ans = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '0') ans++;
        }
        return ans;
    }
}
```