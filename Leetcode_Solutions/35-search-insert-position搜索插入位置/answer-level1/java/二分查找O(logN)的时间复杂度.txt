### 解题思路
二分查找，根据给定的数字进行查找，不论是否存在，都会追踪到最接近target的下标

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
    int res = 0;
        int start = 0;
        if (nums == null || nums.length < 1) {
            return 0;
        }
        if (nums.length == 1) {
            return target > nums[0] ? 1 : 0;
        } else {
            if (nums[0] > target) {
                return 0;
            }
            if (nums[nums.length - 1] < target) {
                return nums.length;
            }
        }
        int end = nums.length - 1;
        while (start <= end) {
            res = (end - start) / 2 + start;
            if (nums[res] > target) {
                end = res - 1;
            } else if (nums[res] == target) {
                return res;
            } else {
                start = res + 1;
            }
        }
        return start;
    }
}
```