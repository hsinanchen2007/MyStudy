### 解题思路

开始想着可以先找，然后在排序，但是存在着重复的，所以就不是原思路了。
看了解答里面的三指针法才想到这道题应该怎么做。找到哪个最小，然后在更新这个指针。

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            int min = Math.min(dp[i2] * 2, Math.min(dp[i3] * 3, dp[i5] * 5));
            if (min == dp[i2] * 2) 
                i2++;
            if (min == dp[i3] * 3) 
                i3++;
            if (min == dp[i5] * 5) 
                i5++;
            dp[i] = min;
        }
        return dp[n - 1];
    }
}
```