### 解题思路
遍历并计数

### 代码

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        for(int i = 0; i < nums.Length; i++)
        {
            if(dict.ContainsKey(nums[i]))
            {
                dict[nums[i]]++;
            }else
            {
                dict.Add(nums[i], 1);
            }

            if(dict[nums[i]] > nums.Length / 2.0)
            {
                return nums[i];
            }
        }

        return -1;
    }
}
```