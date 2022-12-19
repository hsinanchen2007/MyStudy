### 解题思路
暴力法

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for(int i=0;i<nums.Length;i++)
        {
            for(int j=i+1;j<nums.Length;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return new int[2]{i,j};
                }
            }
        }
        return null;
    }
}
```