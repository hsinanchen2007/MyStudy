### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private static final int DEFAULT = -1;
    public int[] searchRange(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return new int[] {DEFAULT , DEFAULT};
        }

        int length = nums.length;
        int left = 0;
        int right = length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                int tmpLeft = mid;
                while (tmpLeft >= 0 && nums[tmpLeft] == target) {
                    tmpLeft--;
                }
                int tmpRight = mid;
                while (tmpRight < length && nums[tmpRight] == target) {
                    tmpRight++;
                }
                return new int[] {tmpLeft + 1, tmpRight - 1};
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return new int[] {DEFAULT, DEFAULT};
    }
}
```