### 解题思路
二分，乱

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (null == nums || 0 == nums.length) {
return new int[]{-1, -1};
        }

        int left = searchL(nums, 0, nums.length - 1, target);
        if (left == -1) {
            return new int[]{-1, -1};
        }

        int right = searchR(nums, 0, nums.length - 1, target);
        return new int[]{left, right};
    }

    private int searchL(int[] nums, int target) {
        return searchL(nums, 0, nums.length - 1, target);
    }

    private int searchR(int[] nums, int target) {
        return searchR(nums, 0, nums.length - 1, target);
    }

    private int searchL(int[] nums, int be, int end, int target) {
        int l = be;
        int r = end;
        while (l < r) {
            int middle = (l + r) / 2;
            int value = nums[middle];
            if (value < target) {
                l = middle + 1;
            } else if (value > target) {
                r = middle - 1;
            } else {
                if (middle == l) {
                    break;
                } else if (nums[middle - 1] < value) {
                    l = middle;
                } else {
                    r = middle - 1;
                }
            }

        }

        return nums[l] == target ? l : -1;
    }

    private int searchR(int[] nums, int be, int end, int target) {
        int l = be;
        int r = end;
        while (l < r) {
            int middle = (l + r + 1) / 2;
            int value = nums[middle];
            if (value < target) {
                l = middle + 1;
            } else if (value > target) {
                r = middle - 1;
            } else {
                if (middle == r) {
                    break;
                } else if (nums[middle + 1] > value) {
                    r = middle;
                } else {
                    l = middle + 1;
                }
            }

        }

        return nums[r] == target ? r : -1;
    }
}
```