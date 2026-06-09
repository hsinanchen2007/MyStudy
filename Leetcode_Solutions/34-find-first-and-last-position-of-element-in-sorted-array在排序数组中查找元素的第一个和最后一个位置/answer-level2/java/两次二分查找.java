### 解题思路
用2次二分查找，不同的策略

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return new int[]{-1, -1};
        }
        //1.二分查找左边界
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;//往左靠
            if (nums[mid] < target) {
                left = mid + 1;//分出这种情况避免死循环
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) {
            return new int[]{-1, -1};
        } 
        int num1=left;
        //1.二分查找右边界
        left = 0;
        right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;//往右靠
            if (nums[mid] > target) {
                right = mid - 1;//避免死循环
            } else {
                left = mid;
            }
        }
        int num2=right;
        return new int[]{num1, num2};
    }
}
```