### 解题思路
一次遍历
相同的元素满足条件直接return，否则不add到字典

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) 
    {
        Dictionary<int,int> dic = new Dictionary<int,int>();
        for(var i =0;i<nums.Length;i++)
        {
            var value = target-nums[i];
            if(dic.Keys.Contains(value))
            {
                return new int[]{dic[value],i};
            }
            if(dic.Keys.Contains(nums[i])==false)
            {
                dic.Add(nums[i],i);
            }
        }
    return new int[]{0,0};
    }
}
```