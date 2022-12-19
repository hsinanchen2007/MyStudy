```
public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return -1;
        // 在边界以外
        if (nums[0] > target || nums[nums.length - 1] < target)
            return -1;

        return search(nums, target, 0, nums.length - 1);
    }

    public int search(int[] nums, int target, int low, int high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;
            // 找不到时(这里要在上面的if之后.
            // low=mid=high,即就这一个位置,经过上面的检查还不是要找的,那就没了)
        else if (low == high)
            return -1;
        else if (nums[mid] < target)
            return search(nums, target, mid + 1, high);
        else
            return search(nums, target, low, mid - 1);
    }
```
