### 解题思路
这道题的关键在于状态的转移，一个状态要遍历前面的n个状态才能得到，其实就是序列的划分

### 代码

```java
class Solution {
    public int minCut(String s) {
        int len = s.length();
        int[] dp = new int[len];
        for (int i = 0; i  < len; i++) dp[i] = -1;
        dp[0] = 0;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= i; j++) {
                boolean b;
                if (i == len - 1) b = isReverse(s.substring(j));
                else b = isReverse(s.substring(j, i + 1));
                if (b) {
                    if (j == 0) dp[i] = 0;
                    else if (dp[i] == -1 || dp[i] > dp[j - 1] + 1) dp[i] = dp[j - 1] + 1;
                }
            }
        }
        return dp[len - 1];
    }

    boolean isReverse(String s) {
        String s1 = new StringBuilder(s).reverse().toString();
        return s1.equals(s);
    }
}
```