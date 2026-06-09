### 解题思路

定义两个指针：
i指向偶数，j指向奇数
空间复杂度o(1)，时间复杂度O(n)

### 代码

```java
class Solution {
    // 双指针 o(n)遍历
    public int[] exchange(int[] nums) {
        for (int i = 0, j = 0; i < nums.length && j < nums.length;) {
            if(i < j && (nums[i] & 1) == 0 && (nums[j] & 1) != 0) {
                swap(nums, i, j);
                i ++;
                j ++;
            }
            // 奇数
            if ((nums[i] & 1) != 0) i ++;
            // 偶数
            if (j < nums.length && ((nums[j] & 1) == 0 || i > j)) j ++;
        }
        return nums;
    }
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```