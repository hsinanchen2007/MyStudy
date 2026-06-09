### 解题思路
此处撰写解题思路
执行用时 :
2 ms
, 在所有 Java 提交中击败了
99.04%
的用户
内存消耗 :
37.6 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        int tmp1 = 0, tmp2 = 0, tmp3 = 0;
        for (int i = 1; i < n; i++){
            tmp1 = dp[a] * 2;
            tmp2 = dp[b] * 3;
            tmp3 = dp[c] * 5;
            dp[i] = Math.min(Math.min(tmp1, tmp2), tmp3);
            if (dp[i] == tmp1) a++;
            if (dp[i] == tmp2) b++;
            if (dp[i] == tmp3) c++;
            tmp1 = 0;
            tmp2 = 0;
            tmp3 = 0;
        }
        return dp[n - 1];
    }
}
```