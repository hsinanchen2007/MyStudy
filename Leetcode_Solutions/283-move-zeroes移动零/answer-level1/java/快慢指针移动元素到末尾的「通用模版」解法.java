### 解题思路
此模版适用于将数组中指定元素移动到数组末尾的所有题型，便于理解、记忆。例如：[26. Remove Duplicates from Sorted Array](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        for (int fast = 0, slow = 0; fast < nums.length; fast++) {
            if (nums[fast] != 0) {
                swap(nums, slow, fast);
                slow++;
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```