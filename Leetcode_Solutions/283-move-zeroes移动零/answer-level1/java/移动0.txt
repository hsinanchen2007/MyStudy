### 解题思路
1. 使用双指针从左开始遍历，如果从右开始移动操作多。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        if(nums == null || nums.length == 0) return;
        int j = 0;
        for(int i = 0; i < nums.length; i++)
            if(nums[i] != 0) nums[j++] = nums[i];
        for(; j < nums.length; j++)
            if(nums[j] != 0) nums[j] = 0;
    }
}
```