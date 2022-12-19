### 解题思路
第二维最长子序列,先排序,然后在第二维dp.最基础的dp.
### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */
import java.util.Arrays;

public class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes.length <= 1) {
            return envelopes.length;
        }
        /**
         * 排序后,求最长子序列
         * dp[i]表示以i为结尾的最长子序列
         */
        Arrays.sort(envelopes, ((o1, o2) -> o1[0] == o2[0] ? o2[1] - o1[1] : o1[0] - o2[0]));
        int[] dp = new int[envelopes.length];
        for (int i = 0; i < envelopes.length; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[j][1] < envelopes[i][1]) {
                   dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        Arrays.sort(dp);
        return dp[envelopes.length - 1];
    }
}

```