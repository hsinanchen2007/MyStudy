### 解题思路
二分法 参考33题

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int mid;
        int start = 0;
        int end = nums.length - 1;

        int min = nums[0];
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[end] > nums[mid]) {
                //  后半段有序 最小值在前半段
                end = mid -1;
            } else {
                //  前半段有序 最小值在后半段
                start = mid + 1;
            }
            min = Math.min(min, nums[mid]);
        }
        return min;
    }
}
```