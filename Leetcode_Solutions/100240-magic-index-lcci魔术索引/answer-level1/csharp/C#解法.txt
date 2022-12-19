遍历数据，判断当前索引值的情况，有以下三种
1、nums[i] == i; return i;
2、nums[i] > i; i = nums[i];
3、nums[i] < i; i++;

代码如下
```
public class Solution {
    public int FindMagicIndex(int[] nums) {
        int len = nums.Length;
        int i = 0;
        while(i < len)
        {
            if(nums[i] == i)
                return i;
            else if(nums[i] > i)
                i = nums[i];
            else
                i++;
        }
        return -1;
    }
}
```
