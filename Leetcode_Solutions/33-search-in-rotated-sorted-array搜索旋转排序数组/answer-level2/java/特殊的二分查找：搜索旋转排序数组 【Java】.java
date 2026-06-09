logN的时间复杂度提示我们用二分查找
二分查找的关键点在于找到中间值以后，如何判断接下来要搜索左边半段还是右边半段。
通过规律发现：
如果a[mid]>a[right].则左边是有序的
如果a[mid]<a[right].则右边是有序的

我们只要在在有序的半边，根据首尾两个元素，判断目标值是否在有序区间，从而达到判断搜索区间的目的。
```

    public int search(int[] nums, int target) {
    if (nums == null || nums.length == 0) {
            return -1;
        }
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (nums[mid] > nums[right]) {
                //说明前半段是有序的
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                //后半段是有序的
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
```
