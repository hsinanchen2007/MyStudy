### 解题思路
方法一：动态规划思想
时间复杂度： O(n)；
空间复杂度： O(n)。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];

        int[] dp = new int[nums.length];
        int max = nums[0];

        dp[0] = nums[0];
        for(int i=1; i<nums.length; i++){
            dp[i] = Math.max(nums[i], nums[i]+dp[i-1]);
            max = max > dp[i] ? max : dp[i];
        }
        return max;
    }
}
```

### 解题思路
方法二：贪心算法思想
时间复杂度： O(n)；
空间复杂度： O(1)。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
                
        int res = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (sum > 0)
                sum += num;
            else
                sum = num;
            res = Math.max(res, sum);
        }
        return res;
    }
}
```