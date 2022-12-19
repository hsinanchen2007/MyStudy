### 解题思路
异或位运算

### 代码

```csharp
public class Solution {
    public int MissingNumber(int[] nums) {
        var result = 0;
        var length = nums.Length;
        for (int index = 0; index < length; index++)
        {
            result ^= nums[index];
            result ^= index;
        }
        result ^= length;
        return result;
    }
}
```