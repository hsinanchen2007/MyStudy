### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1, pivot = 0;
        while (left <= right) {
            if (left == right) return nums[left];
            if (nums[left] < nums[right]) return nums[left];
            pivot = (left + right) >> 1;
            // 若有重复元素，可能出现left和pivot的值相等
            if (nums[left] == nums[pivot]) {
                // 退化成顺序搜索
                for (int i = left + 1; i <= right; i++) {
                    if (nums[i] < nums[i - 1]) return nums[i];
                }
                // 全部元素相同
                return nums[left];
            }
            if (nums[left] < nums[pivot]) {
                left = pivot + 1;
            } else {
                right = pivot;
            }
        }
        return -1;
    }
}
```