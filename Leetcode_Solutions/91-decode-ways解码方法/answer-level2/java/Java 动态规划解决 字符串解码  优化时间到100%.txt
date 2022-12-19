### 解题思路
递归 -》 动态规划 -》 动态规划优化

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        // “12” -> AB or L 即两种结果，返回2
        // 要么是每位数字单独替换为一个对应字符，但0数字要和前面的元素结合构成两位数对应的字符
        // 要么是两个连续数字替换为一个对应字符，替换的前提条件是小于等于26
        // 针对一个起始地址他的可能替换数目为：以自己单独替换为一个字符的可能性+以自己和后一个组成两位数替换字符的可能性
        if (s == null || s.length() == 0) {
            return 0;
        }
        int length = s.length();
        // int[] dp = new int[length + 1];
        // dp[length] = 1;
        // dp[length - 1] = (s.charAt(length - 1) == '0') ? 0 : 1;
        int dpLast = 1;
        int dpPre = (s.charAt(length - 1) == '0') ? 0 : 1;
        for (int i = length - 2; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                dpLast = dpPre;
                dpPre = 0;
                continue;
            }
            int num = (s.charAt(i) - '0') * 10 + (s.charAt(i + 1) - '0');
            if (num <= 26) {
                int tmp = dpPre + dpLast;
                dpLast = dpPre;
                dpPre = tmp;
                // dp[i] = dp[i + 1] + dp[i + 2];
            } else {
                // dp[i] = dp[i + 1];
                dpLast = dpPre;
            }
        }

        return dpPre; // 使用两个变量记录状态转移方程中需要的两个点即可

        // return dp[0]; // 递归数组，记忆下所有的情况

        // return func(s, 0); // 递归实现
    }

    public int func(String s, int start) {
        if (start == s.length()) {
            // 走到最后了
            return 1;
        }
        if (s.charAt(start) == '0') {
            // '0'字符无对应可能性
            return 0;
        }

        int ans1 = func(s, start + 1);
        int ans2 = 0;
        if (start < s.length() - 1) {
            // 具有构成两位数的可能性
            int num = (s.charAt(start) - '0') * 10 + (int)(s.charAt(start + 1) - '0');
            if (num <= 26) {
                ans2 = func(s, start + 2);
            }
        }

        return ans1 + ans2;
    }
}
```