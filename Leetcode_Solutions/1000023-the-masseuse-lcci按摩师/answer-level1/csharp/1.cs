### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int Massage(int[] nums) {
        if(nums.Length == 0) return 0;
         if(nums.Length == 1) return nums[0];
         int dp0 = nums[0];
         int dp1 = nums[1];
         for(int i = 2; i < nums.Length; i++)
         {
             int dpt0 = Math.Max(dp0, dp1);
             int dpt1 = dp0 + nums[i];

             dp0 = dpt0;
             dp1 = dpt1;
         }

         return Math.Max(dp0, dp1);
    }
}

```