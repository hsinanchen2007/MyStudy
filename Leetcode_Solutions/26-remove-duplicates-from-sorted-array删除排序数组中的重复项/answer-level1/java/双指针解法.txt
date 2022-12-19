### 解题思路
此处撰写解题思路
1. 通过双指针求解，可以理解为：遇到第几个不同的数，就给数组第几位赋值
2. 设i为不同的个数，需要注意的是，第0个数默认不相同，因此初始值i=1
3. 从1开始for循环遍历数组，一旦遇到变化的数值，即对nums[i]进行赋值，然后i++
4. 最后返回i的个数

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        // 数组长度为0，直接返回
        if (nums.length == 0) {
            return 0;
        }
        int i = 1; // 不相同个数，第0个默认不相同，不需处理
        for (int j = 1; j < nums.length; j++) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}
```