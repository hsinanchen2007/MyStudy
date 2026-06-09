
```
public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        int mid;
        int start = 0;
        int end = nums.length - 1;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[end] > nums[mid]) {
                //  后半段有序
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                //  前半段有序
                if (target < nums[mid] && target >= nums[start]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

        }
        return -1;
    }
```
