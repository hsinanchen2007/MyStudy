## 逻辑简单的二分查找解法，通俗易懂
![image.png](https://pic.leetcode-cn.com/bb582c3a53ec4e6be29befc9de7c2c9a30c3d8fa9f41ce7af6713b19450871ed-image.png)
```java
    public int[] searchRange(int[] nums, int target) {
        int[] ret = new int[2];
        ret[0] = findFirst(nums, target);
        ret[1] = findLast(nums, target);
        return ret;
    }

    private int findLast(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            int mid = (low + high) >>> 1;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if ((mid == nums.length - 1) || (nums[mid + 1] != target)) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }

    private int findFirst(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            int mid = (low + high) >>> 1;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if ((mid == 0) || (nums[mid - 1] != target)) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
```
注意只有最后的 `else` 里面的条件不一样