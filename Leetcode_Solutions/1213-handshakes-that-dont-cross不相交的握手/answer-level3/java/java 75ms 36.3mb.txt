### 解题思路
动态规划，需要注意int相乘导致溢出问题，需要先cast到long再取摸。

### 代码

```java
class Solution {
    public int numberOfWays(int num_people) {
        int[] dp = new int[num_people+1];
        dp[0] = 1;
        dp[2] = 1;
        int mod = 1000000007;
        for (int i = 4; i<=num_people; i+=2){
            for (int j = 0; j <= i - 2; j += 2) {
                dp[i] = (int) ((dp[i] + ((long) dp[j]*dp[i-2-j])%mod)%mod);
            }
        }
        return dp[num_people];
    }
}
```