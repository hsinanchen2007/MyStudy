### 解题思路
首先定义一个`position`位置，`left`参数，初始值为数组头部与`right`参数初始值为数组尾部，然后进入while循环，每次都查找中间位置，如果值相同，返回索引下标值，如果大于目标值，则在左侧继续搜索，如果小于目标值，则在右侧继续搜索。

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int position = 0;
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            position = left + (right - left) / 2;
            if (nums[position] == target) {
                return position;
            }
            if (nums[position] > target) {
                right = position - 1;
            } else {
                left = position + 1;
            }
        }
        return -1;
    }
}
```