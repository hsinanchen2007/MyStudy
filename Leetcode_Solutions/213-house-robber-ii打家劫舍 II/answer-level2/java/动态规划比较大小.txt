### 解题思路
在这里由于是环形的排列，所以需要考虑第一个和最后选和不选的关系，所以这里只需要比较从第一个到n-1个的最大值和从第二个到第n个的最大值，这部分可以直接用动态规划求解

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0 || nums == null) {
            return 0;
        }

        if(nums.length == 1)
            return nums[0];
        int n = nums.length;
        return Math.max(rob_by_range(nums,0,n-2),rob_by_range(nums,1,n-1));
    }

    public int rob_by_range(int[] nums,int start,int end) {
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp_i = 0;
        for (int i = end; i >= start; i--) {
            dp_i = Math.max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
}
```