### 解题思路
dp[i] 表示到i位置的一共有多少个等差数列。
如果num[i-2] num[i-1] num[i] 满足是等差数列，新加了nums[i+1]，满足nums[i-1] nums[i] nums[i+1]也是等差。
那么num[i-2] num[i-1] num[i] nums[i+1] 都是等差了，dp[i+1] = dp[i]
但是nums[i-1] nums[i] nums[i+1] 没被计算到，所以正确的递归是dp[i+1] = dp[i] + 1;

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if(A.length < 3)
            return 0;
        
        int[] dp = new int[A.length];
        int res = 0;
        
        for(int i = 2; i < A.length; i++){
            if(A[i-1] * 2 == A[i] + A[i-2]){
                dp[i] = dp[i-1] + 1;
                res += dp[i];
            }
        }
        
        return res;
    }
}
```