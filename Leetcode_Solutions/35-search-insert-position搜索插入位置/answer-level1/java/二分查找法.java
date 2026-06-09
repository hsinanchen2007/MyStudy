```
public int strStr(int nums[], int target) {
        int len = nums.length;
        int left = 0, right = len -1;
        int mid = (left + right) / 2;
        while (left < right) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        return nums[left] < target ? left + 1 : left;
    }
```
