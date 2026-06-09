### 解题思路
采用暴力解决，从第一个数字开始，依次计算该数字与它后面数字的和，如果符合要求，立即返回。如果最终未找到符合要求的两个数，则直接返回空。

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for (int i = 0; i < nums.Length - 1; i++)
        {
            for (int j = i + 1; j < nums.Length; j++)
            {
                if (nums[i]+nums[j]==target)
                    return new int[] {i,j};
            } 
        }
        return new int[]{};
    }
}
```