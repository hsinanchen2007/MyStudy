### 解题思路
二分法没啥可说的
### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1, -1};
        if (nums.length == 0) return result;
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = mid;
                right = left;
                while (left - 1 >= 0 && nums[left - 1] == target) {
                    left--;
                }
                while (right + 1 < nums.length && nums[right + 1] == target) {
                    right++;
                }
                result[0] = left;
                result[1] = right;
                break;
            } else {
                right = nums[mid] > target ? mid-1 : right;
                left = nums[mid] > target ? left : mid+1;
            }
        }
        return result;
    }
}
```