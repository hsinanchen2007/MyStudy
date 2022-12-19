优化：预先遍历一下字符串记录下标i到j是否是回文字符串，然后再dp
```
class Solution {
    public int minCut(String s) {
        int n = s.length();
        char[] arr = s.toCharArray();
        int[] dp = new int[n+1];
        dp[0] = -1;
        boolean[][] isSymmetry = getSymmetry(arr);
        for (int i=1; i<n; i++) {
            dp[i+1] = 1 + dp[i];
            for (int j=i-1; j>=0; j--)
                if (isSymmetry[j][i]) {
                    dp[i+1] = Math.min(dp[i+1], dp[j] + 1);
                }
        }
        return dp[n];
    }

    boolean[][] getSymmetry(char[] arr) {
        int n = arr.length;
        boolean[][] ans = new boolean[n][n];
        for (int k=0; k<2*n-3; k++) {
            int left = k / 2;
            int right = (k & 1) == 0 ? left + 1 : left + 2;
            while (left >=0 && right < n) {
                if (arr[left] == arr[right]) ans[left][right] = true;
                else break;
                left--;
                right++;
            }
        }
        return ans;
    }
}
```
