# 动态规划

代码如下：

```C#
public class Solution {
    public int Rob(int[] nums) {
        var len = nums.Length;
        if (len == 0) return 0;
        if (len == 1) return nums[0];

        var list = new List<int>
        {
            nums[0],
            Math.Max(nums[0], nums[1])
        };
        for (var i = 2; i < len; i++)
        {
            list.Add(Math.Max(list[i - 1], list[i - 2] + nums[i]));
        }
        return list[len - 1];
    }
}
```
