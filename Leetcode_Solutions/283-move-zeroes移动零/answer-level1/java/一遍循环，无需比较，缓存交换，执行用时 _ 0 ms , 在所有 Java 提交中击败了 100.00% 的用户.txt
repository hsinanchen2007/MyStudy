### 解题思路
1. i，j两个指针，i作为遍历index；j储存要交换数据的index
2. 循环遍历数组，如果i对应的是0不用管，i指针向后，j指针不变，因为0是要被交换的
3. 如果i对应的不是0，将这个值用tmp存起来，将nums[i]置0，再将要交换的位置nums[j]赋值tmp；先置0避免了比较i和j是否相等

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        for (int i = 0, j = 0, tmp = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                tmp = nums[i];
                nums[i] = 0;
                nums[j] = tmp;
                j++;
            }
        }
    }
}
```