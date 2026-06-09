### 解题思路
典型的动态规划，，由于i-1的元素被取之后，i的元素是无法使用的，所以有
dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i])

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int n = nums.length;
        if(n == 0) return 0;
        int pre2 = 0;
        int pre1 = 0;
        for(int i = 0; i < n; i++){
            int cur = Math.max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = cur;
        } 
        return pre1;
    }
}
```