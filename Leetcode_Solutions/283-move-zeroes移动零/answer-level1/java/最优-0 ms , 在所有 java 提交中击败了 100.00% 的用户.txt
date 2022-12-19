### 解题思路
首先定义一个用来标识移动后非零数组的下标索引，循环遍历数组，找到当前不等于零的值赋值到定义的下标索引，同时自增下标索引值。中间判断下标索引不等于当前遍历数组的下标是为了**规避**赋值后原位置的值需要做处理

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int length = nums.length;
        int currentIndex = 0;
        for (int i=0; i<length; i++) {
            if (nums[i] != 0) {
                nums[currentIndex] = nums[i];
                if (currentIndex != i) {
                    nums[i] = 0;
                }
                currentIndex++;
            }
        }
    }
}
```