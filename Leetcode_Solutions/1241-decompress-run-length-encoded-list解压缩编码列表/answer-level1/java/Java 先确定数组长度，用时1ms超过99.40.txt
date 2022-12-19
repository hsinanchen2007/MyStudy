### 解题思路
先确定数组长度可以提速的原因：
无论是先用list存放，还是初始化为足够长的数组，最终都需要额外进行∑nums[2i+1]次判断与赋值；
而获取长度只需要额外的50次判断(i)，50次计算i，50次计算len，以及50次赋值，总共200次操作。

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int len = 0;
        for(int i = 0; i < nums.length; i += 2)
            len += nums[i];

        int index = 0;
        int[] arr = new int[len];
        for(int i = 0; i < nums.length; i += 2)
            for(int j = 0; j < nums[i]; j ++)
                arr[index++] = nums[i+1];
        return arr;
    }
}
```