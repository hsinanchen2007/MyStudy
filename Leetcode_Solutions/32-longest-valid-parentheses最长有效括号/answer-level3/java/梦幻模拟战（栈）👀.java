### 解题思路
想法类似栈吧，代码遇到左括号辅助数组置0，遇到右括号就去找左侧最近的左括号，如果在查找的过程中遇到
1，表示已经匹配，继续找；
0，表示左括号，双双标记成1；
-1，表示右括号，肯定不能进行匹配，并把当前下标置成-1；
最后统计最长的1的个数
如果遇上很多"((((()))))"这样的括号组合应该会很慢😭

### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        char[] c = s.toCharArray();
        int len = c.length;
        if (len < 2) return 0;
        int ans = 0;
        int[] dp = new int[len + 1];
        if(c[0] == ')') 
            dp[1] = -1;
        int right = 0;
        for (int i = 2; i <= len; i++) {
            if (c[i - 1] == '(') dp[i] = 0;
            else {
                int end = i - 1;
                while (end > right) {
                    if (dp[end] == -1) {
                        dp[i] = -1;
                        right = end;
                        break;
                    }
                    if (dp[end] == 0) {
                        dp[end] = 1;
                        dp[i] = 1;
                        break;
                    }
                    end--;
                }
                if (end == right) dp[i] = -1;
            }
        }
        int cur = 0;
        for (int i : dp) {
            if (i == 1) {
                cur++;
                ans = Math.max(ans,cur);
            }else cur = 0;
        }
        return ans;
    }
}
```