### 解题思路
既然是递增排好序的，那直接用折半查找

### 代码

```java
class Solution {

    /**
    * 既然是递增排好序的，那直接用折半查找
    **/
    public int missingNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        int low = 0;
        int high = nums.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] != mid) {
                // 如果不相等，说明前面位置缺失，这时候处理high右边
                high = mid - 1;
            } else {
                // 如果相等，说明前面位置没有缺失，这时候处理low 左边
                low = mid + 1;
            }
        }
        // 用来判断在前面还是在后面
        return nums[low] == low ? nums[low] + 1 : nums[low] - 1;
    }
}
```