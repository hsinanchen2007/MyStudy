### 解题思路
将数组[0, index)维护为无重复元素的集合；

因为是排序好的数组，所以遇到与index-1位置上不同的元素时，就覆盖index位置的值，即无重复元素集合的元素+1，并移动index。

遍历结束后，返回无重复元素集合的大小（即index的位置下标）。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null) {
            return -1;
        }
        if (nums.length == 0) {
            return 0;
        }
        int index = 1;  // [0, index)为无重复元素集合
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != nums[index-1]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
}
```