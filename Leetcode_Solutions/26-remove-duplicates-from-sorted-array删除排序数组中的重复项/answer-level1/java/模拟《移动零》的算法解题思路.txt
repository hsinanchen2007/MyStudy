### 解题思路

1. 变量j储存下一个不重复的数字该存放的下标。
2. 变量mark 存上一个循环值，用于和当前循环值比较是否是重复项。
3. 循环遍历数组，下标从1开始。
4. 如果循环当前值和上一个值不相等，那么就更新j下标对应的值，然后更新mark的值，然后j也需要想后挪一位以便储存新值。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int j = 1; int mark = nums[0];
        for (int i = 1; i< nums.length; i++)
        {
            if (nums[i] != mark)
            {
                nums[j] = nums[i];
                mark = nums[i];
                j++;
            }
        }
        return j;
    }
}
```