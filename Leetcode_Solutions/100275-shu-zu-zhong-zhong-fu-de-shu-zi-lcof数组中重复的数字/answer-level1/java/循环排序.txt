### 解题思路
循环排序
时间复杂度：O(n^2)
空间复杂度：O(1)
执行用时：92.58%
内存消耗：100%

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int i = 0;
        while (i < nums.length) {

            while (nums[i] != nums[nums[i]]) {
                swap(nums, i, nums[i]);
            }
            i++;
        }

        for(i = 0; i < nums.length && nums[i] == i; i++);
        return nums[i];
    }

    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```