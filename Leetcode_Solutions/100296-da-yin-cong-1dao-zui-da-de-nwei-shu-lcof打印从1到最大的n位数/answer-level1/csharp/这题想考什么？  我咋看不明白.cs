### 解题思路


### 代码

```csharp
public class Solution {
    public int[] PrintNumbers(int n) {
        int max = (int)Math.Pow(10, n) - 1;
        int[] nums = new int[max];
        while(max != 0)
        {
            nums[max - 1] = max;
            max--;
        }
        return nums;
    }
}
```