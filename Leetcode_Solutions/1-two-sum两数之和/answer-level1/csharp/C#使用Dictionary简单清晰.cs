### 解题思路
执行用时 :416 ms, 在所有 csharp 提交中击败了67.22%的用户

此思路参照别人解题方法，理解后可运用在许多场景。

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var dc = new Dictionary<int,int>();
        for(var i = 0;i < nums.Length;i++)
        {
            //nums[0] + nums[1] = 9
            //nums[1] = 9 - nums[0];
            if(dc.ContainsKey(target - nums[i]))
            {
                return new int[] {i,dc[target - nums[i]]};
            }
            dc[nums[i]] = i;
        }
        return new int[]{};
    }
}
```