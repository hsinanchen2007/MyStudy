### 解题思路
+ sum 代表以nums[i] 结尾的子数组最大和
+ ans 是所有sum 的最大值，即答案

对于每个数而言都有两种选择，要么接着左边的子数组继续，要么另起炉灶。 sum = max{sum + nums[i], nums[i]}

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE, sum = 0;
        for(int num : nums) {
            sum = Math.max(sum + num, num);
            ans = Math.max(ans, sum);
        }
        return ans;
    }
}
```