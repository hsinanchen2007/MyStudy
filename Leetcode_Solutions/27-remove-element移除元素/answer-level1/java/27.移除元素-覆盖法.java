### 解题思路
设置i索引从0开始，将j索引指向的非val数值放进nums[i], 直到j遍历结束。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {

        int i = 0;
        // i 小于 非0个数且从0 开始填入，j指向非0数
        for(int j = 0; j < nums.length; j++) {
            if (nums[j] != val)
                nums[i++] = nums[j];
        }
        return i;
    }
}
```