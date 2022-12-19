## 双指针法

+ 一个用来保存当前遍历索引

+ 一个用来保存当前最大值的索引

代码如下：

```C#
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        var len = nums.Length;
        if (len == 0) return 0;
        var curr = 0;
        for (var i = 1; i < len; i++)
        {
            if (nums[i] > nums[curr])
            {
                nums[++curr] = nums[i];
            }
        }
        return curr + 1;
    }
}
 ```