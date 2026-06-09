### 解题思路
不缺失情况下的总和 - 当前数组的总和

### 代码

```csharp
public class Solution {
    public int MissingNumber(int[] nums) {
        int sum = 0;
        for(int i = 0; i < nums.Length; i++)
        {
            sum += nums[i];
        }

        var originalSum = nums.Length * (nums.Length + 1) / 2;

        return originalSum - sum;
    }
}
```