O(n)解法：如果前面的那部分值小于0，那么我从当前这个数开始，如果不小于0，那么相加。
eg:[-2,1,-3,4,-1,2,1,-5,4] -> [-2,1,-2,4,3,5,6,1,5]
比如此时索引为1，我们可以看到前面的值加起来小于0，那么我不如从我当前索引开始，因为加上一个负数，肯定会使其变小。
```
class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length == 0)
            return 0;
        int max = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            nums[i] += nums[i - 1] < 0 ? 0 : nums[i - 1];
            max = Math.max(max, nums[i]);
        }
        
        return max;
    }
}
```



归并解法：把数组分为两部分，最大的连续子序列要么在左边的部分，要么在右边的部分，要么在中间包括左边的一部分以及右边的一部分。所以，利用归并的思想，找到这三部分的值进行比较，返回最大的那个值。
```
class Solution {
    public int maxSubArray(int[] nums) {
        return merge(nums, 0, nums.length);
    }
    
    private int merge(int[] nums, int left, int right) {
        if (right - left == 1)
            return nums[left];
        int m = left + ((right - left) >> 1);
        int leftVal = merge(nums, left, m);
        int rightVal = merge(nums, m, right);
        
        int val = 0, maxL = nums[m - 1];
        for (int i = m - 1; i >= left; --i) {
            val += nums[i];
            maxL = Math.max(maxL, val);
        }
        int maxR = nums[m];
        val = 0;
        for (int i = m; i < right; ++i) {
            val += nums[i];
            maxR = Math.max(maxR, val);
        }
        
        int max = Math.max(leftVal, rightVal);
        
        return Math.max(max, maxL + maxR);
    }
}
```
