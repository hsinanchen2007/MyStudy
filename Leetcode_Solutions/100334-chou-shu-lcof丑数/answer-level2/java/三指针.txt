### 解题思路
三指针的想法，比较每一次谁最小，然后再去判断是谁。

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n; i++) {
            int min = Math.min(dp[i2] * 2, Math.min(dp[i3] * 3, dp[i5] * 5));
            
            if(min == dp[i2] * 2) 
                i2++;
            if(min == dp[i3] * 3) 
                i3++;
            if(min == dp[i5] * 5) 
                i5++;
            dp[i] = min;
        }

        return dp[n-1];
    }
}
```