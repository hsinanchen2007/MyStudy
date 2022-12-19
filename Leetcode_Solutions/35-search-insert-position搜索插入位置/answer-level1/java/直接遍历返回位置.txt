### 解题思路
首先，考虑这个题目的特殊情况——当数组长度为0时，直接返回所需要插入的位置0；
然后，考虑一般正常情况下的方法，通过遍历的方法，从头开始，当遇到比自己大或者相等的数时候，返回此时的下标值；
最后，在遍历结束后，说明数组中的均比 target 小，直接返回数组长度。


### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length == 0)
            return 0;
        
        for (int i = 0;i<nums.length; i++) {
            if(nums[i] >= target)
                return i;
        }

        return nums.length;
    }
}
```