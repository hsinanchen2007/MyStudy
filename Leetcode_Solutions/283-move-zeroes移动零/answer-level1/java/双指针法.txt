### 解题思路
必须想到的点，也是对空间复杂度有要求的题型常用的方式：双指针。
此处新建j指针用于记录下一个不为0的数字该存放的位置（下标）。
1. 循环项里发现不为0的数字后，将j下标的值更新。
2. 将i下标对应的值，修改为0； 注意i和j的关系是>=的关系，所以需要加判断，避免把nums[j]的值也修改为0；
3. j自增1，用来储存下一个不为0的位置。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                if (j != i)
                {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
}
```