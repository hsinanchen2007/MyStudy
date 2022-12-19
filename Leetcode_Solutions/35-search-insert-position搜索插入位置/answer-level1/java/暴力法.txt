### 解题思路
遍历数组，目标数和数组中各数进行比对
如果数组中的数大于或者等于目标数时，目标数所在或需插入的位置索引即为i
如果数组中的数均小于目标数，则目标数一定插入至末尾，目标数的索引值即为原数组的长度值

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        for (int i = 0;i < nums.length;i++){
            if (nums[i] >= target) return i;
        }
        return nums.length;

    }
}
```