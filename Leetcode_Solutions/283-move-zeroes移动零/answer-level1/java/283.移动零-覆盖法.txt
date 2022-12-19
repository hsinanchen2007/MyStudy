### 解题思路
使用两个索引i，j. i从0开始开始赋值，j从0开始遍历，遍历到非零元素放入i索引中。直到j遍历到数组末尾，接着从i后填0。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0,j = 0;
        // i 小于 非0个数且从0 开始填入，j指向非0数
        while (j < nums.length) {
            if (nums[j] != 0)
                nums[i++] = nums[j];
            j++;
        }
        for (; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
}
```