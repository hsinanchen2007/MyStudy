```
 public int search(int[] nums, int target) {
        int ind = -1;
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            if (nums[left] > target && nums[right] < target) {
                break;
            }
            if (nums[left] == target) {
                ind = left;
                break;
            }
            if (nums[right] == target) {
                ind = right;
                break;
            }
            if (nums[left] < target) {
                left++;
            }
            if (nums[right] > target) {
                right--;
            }
        }
        return ind;
    }
```
