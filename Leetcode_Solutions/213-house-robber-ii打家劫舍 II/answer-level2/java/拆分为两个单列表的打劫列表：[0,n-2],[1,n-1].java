### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int rob(int[] nums) {
         //循环
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if(nums.length==1)
        {
            return nums[0];
        }

        return Math.max(rob(nums, 0, nums.length-1), rob(nums, 1, nums.length));

    }

    private int rob(int[] nums, int begin, int end) {
        int dp0 = 0;
        int dp1 = 0;
        for (int i = begin; i < end; i++) {
            int dpn = Math.max(dp0 + nums[i], dp1);
            dp0 = dp1;
            dp1 = dpn;
        }
        return dp1;
    }
}
```