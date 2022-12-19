### 解题思路
和[26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/submissions/)思路一样的。对于同类型的题目，可以用如下通用的方法，把maxDuplicateNum改为允许每个元素最多出现次数即可。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        // 允许每个元素最多出现的次数
        int maxDuplicateNum = 2;
        if (nums.length <= maxDuplicateNum) {
            return nums.length;
        }
        int slow = maxDuplicateNum - 1;
        int fast = maxDuplicateNum;
        while (fast < nums.length) {
            if (nums[fast] == nums[slow - (maxDuplicateNum - 1)]) {
                fast++;
            } else {
                swap(nums, ++slow, fast++);
            }
        }
        return slow + 1;
    }

    void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
```