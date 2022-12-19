```
//二分法
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        if (right < 0) {
            return 0;
        }
        //while循环后left == right
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        while (left < nums.length && nums[left] == target) {
            left++;
        }
        return left - right;
    }
}
```
