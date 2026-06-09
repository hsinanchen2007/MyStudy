这道题主要考察二分查找的知识点。直接遍历的话。时间复杂度为O(n),也失去了意义。
无论是写题还是工作，一定要注意边界条件判断。所以写正常逻辑之前，一般要进行一下判空等操作。
```
public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
```
