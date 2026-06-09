### 解题思路
虽然和正常暴力解一个意思，却是要快一点，看来验证结果里面答案基本在数组的前面啊
### 代码
```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) { 
        for (int i = 0; i < nums.Length; i++)
        {
            for (int ii = 0; ii<i; ii++)
            {
                if (nums[ii] == nums[i]) return new int[] {ii,i};
            }
            nums[i] = target - nums[i];
        }
        return new int[] {0,0};
    }
}
```