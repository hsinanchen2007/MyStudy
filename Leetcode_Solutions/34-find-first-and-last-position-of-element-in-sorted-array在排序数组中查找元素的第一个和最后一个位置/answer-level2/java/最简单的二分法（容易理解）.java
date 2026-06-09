### 解题思路
看到log(n)估计无数大佬就会知道肯定要用二分法，我试着用二分法一次性找出left和right，发现太复杂，还是来两轮比较好。
首先是求最左侧的值，参考searchLeft，然后是求最右侧的值，参考searchRight，然后把结果合并即可。

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {

        if (nums.length == 0) {
            return new int[]{-1, -1};
        } else if (nums.length == 1) {
            if (nums[0] == target) {
                return new int[]{0, 0};
            } else {
                return new int[]{-1, -1};
            }
        }

        int left = searchLeft(nums, target, 0, nums.length);
        int right = searchRight(nums, target, 0, nums.length);
        return new int[]{left, right};
    }

    public int searchLeft(int[] nums, int target, int from, int to) {
        // 递归终止条件
        if (to - from <= 1) {
            if (from < 0) {
                return -1;
            } else if (from >= nums.length) {
                return -1;
            }
            if (target == nums[from]) {
                return from;
            } else {
                return -1;
            }
        }

        // 非终止条件，则判断中间值
        int mid = (from + to) / 2;
        int midVal = nums[mid];
        // 三种情况，第一种是相等
        if (midVal == target) {
            // 判断两侧是否满足
            if (mid <= 0 || nums[mid - 1] != target) {
                // 那么mid是最左侧
                return mid;
            } else {
                // 查询左侧找min
                return searchLeft(nums, target, from, mid);
            }
        } else if (midVal < target) {
            // 查询右侧最小值
            return searchLeft(nums, target, mid, to);

        } else {
            // 查询左侧找最大值和最小值
            return searchLeft(nums, target, from, mid);
        }

    }

    public int searchRight(int[] nums, int target, int from, int to) {
        // 递归终止条件
        if (to - from <= 1) {
            if (from < 0) {
                return -1;
            } else if (from >= nums.length) {
                return -1;
            }
            if (target == nums[from]) {
                return from;
            } else {
                return -1;
            }
        }

        // 非终止条件，则判断中间值
        int mid = (from + to) / 2;
        int midVal = nums[mid];
        // 三种情况，第一种是相等
        if (midVal == target) {
            // 判断两侧是否满足
            if (mid + 1 >= nums.length) {
                return mid;
            } else if (mid + 1 >= to || nums[mid + 1] != target) {
                // 那么mid是最右侧
                return mid;
            } else {
                // 查询左侧找min
                return searchRight(nums, target, mid, to);
            }
        } else if (midVal < target) {
            // 查询右侧最小值
            return searchRight(nums, target, mid, to);

        } else {
            // 查询左侧找最大值和最小值
            return searchRight(nums, target, from, mid);
        }
    }
}
```