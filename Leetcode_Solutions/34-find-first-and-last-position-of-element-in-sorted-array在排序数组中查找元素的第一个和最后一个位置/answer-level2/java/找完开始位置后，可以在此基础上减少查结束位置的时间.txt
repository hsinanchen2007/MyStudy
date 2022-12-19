## 思路
基本上由于数组是排过序的，并且提示了复杂度为O(logN)，所以第一感觉一定是尝试二分查找，细节则是在尝试查找开始位置后，只有两种结果：
1. 如果没有找到，则不用尝试找结束位置了，因为数组里根本没有这个数
2. 如果找到了target，则尝试查找结束位置时可以保留start，只重置end

## 代码
```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = new int[]{-1, -1};
        if (nums == null || nums.length == 0) {
            return result;
        }

        int start = 0, end = nums.length - 1;
        int mid;
        while (start < end - 1) {
            mid = (start + end) >> 1;
            if (nums[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (nums[start] == target) {
            result[0] = start;
        } else if (nums[end] == target) {
            result[0] = end;
        }

        if(result[0] == -1) {
            //没找到target
            return result;
        }

        end = nums.length - 1;
        while (start < end - 1) {
            mid = (start + end) >> 1;
            if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (nums[end] == target) {
            result[1] = end;
        } else if (nums[start] == target) {
            result[1] = start;
        }

        return result;
    }
}
```

