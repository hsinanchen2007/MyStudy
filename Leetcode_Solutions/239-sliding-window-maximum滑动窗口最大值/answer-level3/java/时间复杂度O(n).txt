最简单的思路就是对所有窗口进行扫描，不过时间复杂度为O(n*m)。

**优化方案：**
相邻的窗口只有一个数字是不一样的，当对前一个窗口扫描得到的最大值下标仍然存在于下一个窗口时，只需要对窗口最后一位数字与最大值进行比较就可以得出最大值。
时间复杂度降低为O(n)。

**代码(Java)**
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length == 0)
            return new int[]{}; // 鲁棒性
        int[] result = new int[nums.length - k + 1]; // 最大值数组
        int maxIndex = -1; // 最大值下标
        for(int i = 0;i < result.length;i++) {
            if(maxIndex >= i) {
                // 当最大值下标在窗口范围内时直接与窗口最后一位对比
                if(nums[i + k - 1] > nums[maxIndex])
                    maxIndex = i + k - 1;
            }else{
                // 当最大值下标不在窗口范围内时重新扫描窗口更新最大值下标
                maxIndex = i;
                for(int j = i + 1;j < i + k;j++) {
                    if(nums[j] > nums[maxIndex])
                        maxIndex = j;
                }
            }
             result[i] = nums[maxIndex];
        }
        return result;
    }
}
```