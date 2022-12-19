### 解题思路
二分查找：主要是处理nums数组中不存在target的情况
![批注 2020-03-25 231738.png](https://pic.leetcode-cn.com/901048541455590aab5b382908f47dc407f3ed034632623cbd02f88d088ca798-%E6%89%B9%E6%B3%A8%202020-03-25%20231738.png)

### 代码

```java
class Solution {
        public static int search(int[] nums, int target) {
        // base case
        if (nums == null || nums.length == 0)
            return 0;

        int ans = 0; // 结果

        // 找第一个、最后一个target的下标
        int firstIndex = findFirstIndex(nums, target, 0, nums.length - 1);
        int lastIndex = findLastIndex(nums, target, 0, nums.length - 1);

        if (firstIndex != -1 && lastIndex != -1) {
            ans = lastIndex - firstIndex + 1;
        }

        return ans;
    }

    private static int findLastIndex(int[] nums, int target, int l, int r) {
        if (l > r)
            return -1;

        int midIndex = l + ((r - l) >> 1);
        if (nums[midIndex] != target && l == r) // nums数组不存在target
            return -1;

        if (nums[midIndex] == target) {
            while (midIndex + 1 <= r && nums[midIndex + 1] == target) {
                midIndex++;
            }
            return midIndex;
        }else if (nums[midIndex] > target){
            return findLastIndex(nums, target, l, midIndex);
        }else {
            return findLastIndex(nums, target,midIndex + 1, r);
        }

    }

    private static int findFirstIndex(int[] nums, int target, int l, int r) {
        if (l > r)
            return -1;

        int midIndex = l + ((r - l) >> 1);
        if (nums[midIndex] != target && l == r) // nums数组不存在target
            return -1;

        if (nums[midIndex] == target) {
            while (midIndex - 1 >= l && nums[midIndex - 1] == target) {
                midIndex--;
            }
            return midIndex;
        } else if (nums[midIndex] > target) {
            return findFirstIndex(nums, target, l, midIndex);
        } else {
            return findFirstIndex(nums, target, midIndex + 1, r);
        }
    }
}
```