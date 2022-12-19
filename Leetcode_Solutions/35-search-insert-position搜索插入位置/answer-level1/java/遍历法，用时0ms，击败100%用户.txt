### 解题思路
遍历，等于目标值或大于目标值时返回索引，当目标值大于最后一个值时，返回数组长度。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
         for (int i = 0; i < nums.length; i++){
             if (nums[i] == target || nums[i] > target ){
                 return i;
             }
         }
         return nums[nums.length - 1] > target ? 0 : nums.length;
    }
}
```