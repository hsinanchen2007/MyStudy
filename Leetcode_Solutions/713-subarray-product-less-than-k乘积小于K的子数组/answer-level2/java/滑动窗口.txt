```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;

        // 存储乘积小于K的子数组的个数
        int ans = 0;
        // 当前窗口的所有元素的乘积
        int prod = 1;
        
        // 维护滑动窗口
        int left = 0;
        int right = 0;
        while (right < nums.length) {
            // 更新当前窗口的累计乘积
            prod *= nums[right];
            // left 指针移动
            // 移动时机：当前窗口累计乘积大于等于 k
            // 移动策略：将累计乘积除以需要移除的左边的元素值
            while(prod >= k) prod /= nums[left++];

            // 到现在当前窗口的乘积小于 k
            // 计算乘积小于 k 的子数组的个数
            ans += right - left + 1;

            // right 指针移动
            right++;
        }

        return ans;
    }
}
```