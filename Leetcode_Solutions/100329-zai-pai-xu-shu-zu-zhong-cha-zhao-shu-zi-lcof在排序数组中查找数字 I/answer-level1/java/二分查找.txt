### 复杂度分析
时间复杂度：O(logn)
空间复杂度：O(1)

### 解题思路
因为数组有序，想到效率较高的二分查找
如果找到对应数字，则往前往后遍历，得到数字出现次数
若遍历过程中数字变化，则直接退出遍历

### 代码

```java
class Solution {
    /**
     * 思考：1、如何找到这个数 ———— 二分查找
     *      2、找到后如何统计数量 ———— 往两个方向遍历
     */ 
    public int search(int[] nums, int target) {
        int index = find(nums, 0, nums.length - 1, target);

        // 未在数组中找到该数字
        if (index == -1) {
            return 0;
        }

        int i = index - 1, j = index + 1;
        int count = 1;

        // 往前遍历
        while (i >= 0 && nums[i] == target) {
            count++;
            i--;
        }

        // 往后遍历
        while (j < nums.length && nums[j] == target) {
            count++;
            j++;
        }

        return count;
    }

    /**
     * 二分查找
     */
    private int find(int[] nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return find(nums, start, mid - 1, target);
        }
        else {
            return find(nums, mid + 1, end, target);
        }
    }
}
```