### 解题思路
这个问题算是比较简单的，因为是有序的数组，可以预先判断一下target是否超过了数组的最大值

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if (target > nums[nums.length-1]){
            return nums.length;
        }
        int index = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= target) {
                index = i;
                break;
            }
        }
        return index;
    }
}
```