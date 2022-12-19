### 解题思路
比较容易理解,遍历然后record.
### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */

public class Solution {
    public int minCut(String s) {
        /**
         * 比较常规
         * 遍历然后记录
         * dp[i]=min(dp[j]+1 for j in range(i) if s[j+1,i]是回文)
         */
        int[] dp = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (checkIsPalida(s.substring(0, i + 1))) {
                dp[i] = 0;
                continue;
            } else {
                dp[i] = i;
            }
            for (int j = 0; j < i; j++) {
                if (checkIsPalida(s.substring(j + 1, i+1))) {
                    dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[s.length() - 1];
    }

    private boolean checkIsPalida(String s) {
        StringBuilder buffer = new StringBuilder(s);
        return buffer.reverse().toString().equals(s);
    }
}

```