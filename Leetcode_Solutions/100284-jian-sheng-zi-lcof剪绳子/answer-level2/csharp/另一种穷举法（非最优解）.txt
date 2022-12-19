### 解题思路
分成m段的时候，每段长度尽量接近的时候乘积为最大。
所以穷举从分成2段到分成n/2段时的最大值。

### 代码

```csharp
public class Solution {
    public int CuttingRope(int n) {
        int max = 0;
        int mMax = Math.Max(n / 2, 2);
        for (int m = 2; m <= mMax; m++)
        {
            int mod = n % m;
            int rope = n / m;
            int value = rope;
            for (int i = 1; i < m; i++)
            {
                value *= i <= mod ? (rope + 1) : rope;
            }
            if (value > max)
            {
                max = value;
            }
        }
        return max;
    }
}
```