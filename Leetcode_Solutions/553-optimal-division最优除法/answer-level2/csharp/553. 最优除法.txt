### 解题思路
数学分析法，使得分母最小；

### 代码

```csharp
public class Solution {
    public string OptimalDivision(int[] nums) {
        if (nums.Length <= 2) return string.Join("/", nums);
        var builder = new StringBuilder($"{nums[0]}/(");
        builder.Append(string.Join("/", nums.Skip(1)));
        builder.Append(")");
        return builder.ToString();
    }
}
```