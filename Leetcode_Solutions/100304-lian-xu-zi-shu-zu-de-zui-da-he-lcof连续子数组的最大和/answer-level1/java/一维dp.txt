### 解题思路
一位dp
执行用时 :
1 ms
, 在所有 Java 提交中击败了
98.58%
的用户
内存消耗 :
46.1 MB
, 在所有 Java 提交中击败了
100.00%
的用户

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int len = nums.length;
        int dp[] = new int[len];
        int res = Integer.MIN_VALUE;
        dp[0] = nums[0];
        for (int i = 1; i < len; i++){
            dp[i] = Math.max(nums[i] + dp[i-1], nums[i]);
        }
        for (int tmp : dp){
            if (tmp > res) res  = tmp;
        }
        return res;
    }
}
```