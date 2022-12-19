```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        // 存储最终结果
        int ans = 0;
        // 存储当前 window 中 1 的个数
        int windowOneCounts = 0;

        // 维护滑动窗口
        int left = 0;
        int right = 0;
        while (right < nums.length) {
            // 更新当前窗口中 1 的数量
            if (nums[right] == 1) windowOneCounts++;

            // left 指针移动
            // 移动时机：当前窗口大小大于 windowOneCounts + 1
            // 移动策略：如果移出的是 1，需要更新当前窗口中 1 的数量
            if (right - left + 1 > windowOneCounts + 1) {
                if (nums[left] == 1) windowOneCounts--;
                left++;
            }

            // 计算最大连续 1 的个数
            ans = Math.max(ans, right - left + 1);
            
            // right 指针移动
            right++;
        }

        return ans;
    }
}
```