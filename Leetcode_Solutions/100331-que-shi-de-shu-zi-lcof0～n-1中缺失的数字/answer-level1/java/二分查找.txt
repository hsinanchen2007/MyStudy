### 复杂度分析
时间复杂度：O(logn)
空间复杂度：O(1)

### 解题思路
根据题意，
缺失元素之前的元素与下标一一对应；
之后的元素是下标加一后的值

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        return binaryFind(nums, 0, nums.length - 1);
    }

    public int binaryFind(int[] nums, int start, int end) {
        // 当前后指针指向同一位置时
        // 如果 nums[i] > i，由于大于下标时一定是往前收缩区间，因此缺少前一个元素
        // 如果 nums[i] = i，由于一直在向后收缩区间，缺失的是后一个元素
        if (start >= end) {
            return nums[start] == start ? nums[start] + 1 : nums[start] - 1;
        }
        int mid = (start + end) >> 1;

        // 如若元素等于下标，说明缺失元素还在后面
        if (nums[mid] == mid) {
            return binaryFind(nums, mid + 1, end);
        }
        return binaryFind(nums, start, mid - 1);
    }
}
```