看见O(logN)就应该想到二分查找，而且题目说的是有序数组，那就更应该使用二分查找了 
因为本题中包含重复数字，所以当我们找到下标mid时，可以从该下标出发，向左找一个小于target的数然后停下，再从mid出发，找到一个大于target数时停下。需要注意的是一些极端情况，例如数组长度为1时，target在数组中只有一个数时。 代码仅供参考。
```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums.length == 1) {
            if (target == nums[0]) {
                return new int[] { 0, 0 };
            } else {
                return new int[] { -1, -1 };
            }
        }
        int mid = search(nums, 0, nums.length - 1, target);

        int min = mid;
        int max = mid;
        while (min - 1 >= 0) {
            if (nums[min - 1] != target) {
                break;
            } else {
                min--;
            }
        }
        while (max + 1 < nums.length && max >= 0) {
            if (nums[max + 1] != target) {
                break;
            } else {
                max++;
            }
        }
        return new int[] { min, max };
    }

    private int search(int[] nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target && target >= nums[left]) {
            return search(nums, left, mid - 1, target);
        } else {
            return search(nums, mid + 1, right, target);
        }
    }
}
```