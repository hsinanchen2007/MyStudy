### 解题思路
思路很清晰，就是动态规划
`dp[i]`数组表示前`i`个预约可以接到的最长预约时间
对于每一个`i`，都可以选择接或不接
- 接的话，就是`dp[i-2]`加自己`nums[i]`
- 不接的话，就`dp[i-1]`不加自己

看哪个时间长选哪个，遍历数组`nums`，`dp`最后一项就是总的最优时间

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if(nums == null) return 0;
        int len = nums.length;
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        int[] dp = new int[len];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for(int i=2; i<len; i++) {
            dp[i] = Math.max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[len-1];
    }
}
```