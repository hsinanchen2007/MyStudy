```
class Solution {
    public int lengthOfLongestSubstring(String s) {
        // 注意：输入字符串为空的情况
        /*
            dp[i]表示包含第i个字符的向左最长不重复子串的长度
            dp[i+1] = dp[i] +1  if 从i-dp[i]+1到i这段不重复字符串不包含字符s[i+1]
                      x-i+1       if 从i-dp[i]+1到i这段不重复字符串包含字符s[i+1]，从后往前遍历找到最左起点x
            max = max(dp[0],..., dp[n-1])
        */
        if (s == null || s.length() == 0)
            return 0;
        int dp = 1, max = 1;
        for (int i=1; i < s.length(); i++) {
            char ch = s.charAt(i);
            int pt = i - 1; // 前一子问题
            int len = 1;
            // 从后往前遍历
            for (int j = pt; j >= pt - dp + 1 ;j--) {
                if (s.charAt(j) == ch) {
                    break;
                }
                len += 1;
            }
            dp = len;
            if (max < dp)
                max = dp;
        }
        return max;
    }
}
```
