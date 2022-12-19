```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;

        // 维护窗口
        int left = 0;
        int right = 0;
        while (right < nums.length) {
            // left 指针
            // 移动时机：当 right 指向元素为 0 的时候
            // 移动策略：计算当前窗口连续 1 个个数，且将 left 移动到 right 的后一位
            if (nums[right] == 0) {
                ans = Math.max(ans, right - left);
                left = right + 1;
            } 
            // right 指针移动
            right++;
        }
        // 对比最后一个窗口中连续 1 个个数和 ans 
        ans = Math.max(ans, right - left);

        return ans;
    }
}
```