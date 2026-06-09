### 解题思路
此处撰写解题思路 

先排序 再计算出间隔 取最大值；

### 代码

```csharp
public class Solution {
    public int MaximumGap(int[] nums) {
            int gap = 0;
            List<int> gaps = new List<int>();
            if (nums.Count() < 2)
            {
                return 0;
            }
            Array.Sort(nums);
            for (int i = 0; i < nums.Length; i++)
            {
                if (i != nums.Length - 1)
                {
                    gaps.Add(nums[i + 1] - nums[i]);
                }

            }
            gap = gaps.Max();
            return gap;
    }
}
```