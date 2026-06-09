思路分析:

- 这道题的关键就在于理解扩号字符串组成规律，摸清楚规律之后，编码就不是很么难事
- 优先括号字符串有几个性质： 左括号的数量必须等于右括号的数量，字符串必须以`(`开头,以`)`结尾。
![最长有效括号](https://pic.leetcode-cn.com/ec59bee29a01b999fedd5bc9efc661bcdd8a5c45c8ecc39e10cd8b43e7ec09d1.png)


- 根据分析的思路，上暴力递归代码
```
    public int longestValidParentheses2(String s) {
        getRes(s,s.length() - 1);
        return maxLen;
    }

    int maxLen = 0;   // 放一个指针，用于记录最长的结果

    // c为字符串的索引，用于记录每个位置的最长有效括号的长度，只对右括号有效
    private int getRes(String s, int c) {
        // 扣边界
        if(c <= 0) return 0;
        if(s.charAt(c) == '('){  // 如果当前位置是'('，则缩进一位去考虑，此处直接返回0
            getRes(s,c - 1);
            return 0;
        }
        // 到这里c位置只可能是')'
        int ans = 0;
        if(s.charAt(c - 1) == '(') {
            ans = 2 + getRes(s,c - 2);       // 向前走两位
        } else {                                // 如果左边同样为右括号
            int left = getRes(s,c - 1);       // 用一个指针，记录他的值
            if(left != 0 && c - left - 1 >= 0 && s.charAt(c - left - 1 ) == '(') {
                ans = 2 + left + getRes(s,c-left-2);
            }
        }
        maxLen = Math.max(ans,maxLen);           // 每次走到这里都更新maxLen的值
        return ans;
    }
```

- 同样的，老套路，暴力递归改成动态规划。
```
    // 暴力递归改动态规划
    public int longestValidParentheses2(String s) {
        int maxLen = 0;
        int[] dp = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if(i == 0 || s.charAt(i) == '('){
                dp[i] = 0;
            }else{
                if(s.charAt(i - 1) == '('){
                    dp[i] = 2 + (i - 1 > 0 ? dp[i - 2] : 0);
                }else{
                    if(dp[i - 1] != 0 && i - dp[i - 1] > 0 && s.charAt(i - dp[i - 1] - 1) == '('){
                        dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] - 1 > 0 ? dp[i - dp[i - 1] - 2] : 0);
                    }
                    // 其他情况默认为0
                }
            }
            maxLen = Math.max(maxLen,dp[i]);
        }
        return maxLen;
    }
```