### 思路一：

遍历，遇到第一个等于或大于 target 的元素，返回该元素的 index，对于大于 target 的元素的 index 就是应该插入元素的 index。找不到就返回 A.length，即放在最后。

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if(target > nums[nums.length - 1]) {
            return nums.length;
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.length;
    }
}
```

### Result：

Runtime：5ms

Your runtime beats 63.43% of java submissions.

### 思路二：

对有序数组进行二分查找,找到即返回 index，否则，最后返回 low，即为该插入的位置。

### 代码：

时间复杂度O(logn)，空间复杂度O(1)

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if(target > nums[nums.length - 1]) {
            return nums.length;
        }
        int low = 0, high = nums.length - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return low;
    }
}
```

### Result：

Runtime：0ms

Your runtime beats 100% of java submissions.

### 思路二的进一步优化：

在进行二分的时候，**可以顺带判断，减少二分的次数**。即一旦左边界大于目标值或者右边界小于目标值，即可终止操作。

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if(target > nums[nums.length - 1]) {
            return nums.length;
        }
        int low = 0, high = nums.length - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] > target) {
                high = mid - 1;
                if (high >= 0) {
                    if (nums[high] < target) {
                        return high + 1;
                    }
                } else {
                    return 0;
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
                if (low < nums.length) {
                    if (nums[low] > target) {
                        return low;
                    }
                } else {
                    return nums.length;
                }
            } else {
                return mid;
            }
        }
        return low;
    }
}
```