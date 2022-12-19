### 解题思路
记录num[mid],观察可以发现最小值永远在乱序的那一半,通过不断递归当指针相遇即为最小值

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
      int low = 0;
        int high = nums.length - 1;
        if (nums[high] > nums[low]) {
            return nums[low];
        }
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >=nums[low]) {
                low = mid;
            } else high = mid;

        }
        return nums[high];
    }
}
```