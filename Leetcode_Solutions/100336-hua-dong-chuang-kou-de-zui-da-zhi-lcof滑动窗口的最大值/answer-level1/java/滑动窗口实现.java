滑动窗口实现：用max记录一个窗口中的最大值，每次滑动进行判断，如果新滑进来的右边界的数比当前最大值max大的话，那么更新max为这个值，如果max刚好等于即将要淘汰的左边界的值的话，那么需要重新再这个新窗口中寻找最大值max。
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int len = nums.length;
        if (len == 0 || k > len)
            return new int[0];
        
        int[] ans = new int[len - k + 1];
        int max = nums[0];
        for (int i = 1; i < k; i++)
            max = Math.max(max, nums[i]);
        int index = 0;
        ans[index++] = max;
        for (int i = k; i < len; ++i) {
            //如果进来的右边界的数大于之前的最大值的话，那么更新最大值为新进来的右边界的值
            if (max < nums[i]) {
                max = nums[i];
                //如果最大值是即将划走的左边界的值的话，那么需要重新更新需找最大值
            } else if (max == nums[i - k]) {
                max = nums[i - k + 1];
                for (int j = i - k + 1; j <= i; ++j) {
                    max = Math.max(max, nums[j]);
                }
            }
            ans[index++] = max;
        }
        
        return ans;
    }
}
```
