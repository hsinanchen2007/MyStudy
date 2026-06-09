### 解题思路
当我在提交代码的时候，程序报错了，仔细一看，发现nums是一个空数组。另外还有一种特殊情况，就是数组只有一个数字的时候，这样子就直接输出就好了。解题时最主要的步骤是判断当前数字是否为数组的下一项数字的前一位，满足了就继续，不满足就输出已满足的最大项。

### 代码

```csharp
public class Solution {
    public IList<string> SummaryRanges(int[] nums) {
            List<string> list = new List<string>();
            if(nums.Length==0){
                return list;
            }
            else if (nums.Length == 1)
            {
                list.Add(nums[0].ToString());
                return list;
            }
            int start = nums[0];
            int cache = nums[0];
            bool CanContinue = false;
            for (int i = 0; i < nums.Length; i++)
            {
                if (i == 0)
                {
                    if (nums[i + 1] != nums[i] + 1)
                    {
                        list.Add(nums[i].ToString());
                    }
                    continue;
                }
                int num = nums[i];
                if (num - cache == 1)
                {
                    cache = num;
                    CanContinue = true;
                    if (nums.Length == i + 1)
                    {
                        list.Add(start.ToString() + "->" + cache.ToString());
                    }
                }
                else
                {
                    if (CanContinue)
                    {
                        list.Add(start.ToString() + "->" + cache.ToString());
                        CanContinue = false;
                    }
                    start = num;
                    cache = num;
                    if ((nums.Length > i + 1 && nums[i + 1] != nums[i] + 1)|| (nums.Length == i + 1))
                    {
                        list.Add(nums[i].ToString());
                    }
                }
            }
        return list;
    }
}
```