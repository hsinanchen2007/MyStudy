看到时间复杂度为O(logN)应该条件反射和二分查找有关系。
但是二分查找的前提是数组必须有序。
在本题中，数组原先是有序的，只是在某个点上进行了旋转，所以一旦我们将数组一分为二，则其中一边一定是有序的，另外一边有可能是有序的。
因此我们可以先找到数组有序的一部分，然后对其进行二分查找，不断递归即可。
代码仅供参考
```
class Solution {
    public int search(int[] nums, int target) {
        return search(nums, 0, nums.length - 1, target);
    }

    private int search(int[] nums, int left, int right, int target) {
        if (left > right)
            return -1;
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        // 说明右边有序
        if (nums[mid] < nums[right]) {
            if (target > nums[mid] && target <= nums[right]) {
                return search(nums, mid + 1, right, target);
            } else {
                return search(nums, left, mid - 1, target);
            }
        } else {
            if (target < nums[mid] && nums[left] <= target) {
                return search(nums, left, mid - 1, target);
            } else {
                return search(nums, mid + 1, right, target);
            }
        }
    }
}
```