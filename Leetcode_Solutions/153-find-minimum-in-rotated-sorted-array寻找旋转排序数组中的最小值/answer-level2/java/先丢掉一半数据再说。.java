### 解题思路
借鉴折半查找，但是没有那么有规律，先丢掉一半，然后再遍历找到一个最小的值

### 代码

```java
class Solution {
     public int findMin(int[] nums) {
        int len = nums.length;
        if (len == 1) {
            return nums[0];
        }
        int right = len - 1;
        int left = 0;
        int mid = left + (right - left) / 2;
        int min = Integer.MAX_VALUE;
        if (nums[mid] >= nums[left]) {
            if (nums[mid] < nums[right]) {
                return nums[0];
            }
            left = mid + 1;
            while (left <= right) {
                if (nums[left] < nums[left - 1]) {
                    return nums[left];
                } else {
                    left++;
                }
            }
        } else {
            right = mid;
            while (left < right) {
                if (nums[right - 1] < nums[right]) {
                    min = Math.min(nums[right - 1], min);
                } else {
                    return nums[right];
                }
                right--;
            }
        }
        return min;
    }
}
```