### 解题思路
C# 前缀和

### 代码

```csharp
public class Solution {
    public int MinFlipsMonoIncr(string S) {
        // 统计当前及之前所有数字中 '0' 的个数
        var zeroCounts = new int[S.Length];
        zeroCounts[0] = S[0] == '0' ? 1 : 0;
        for (int index = 1; index < S.Length; index++)
        {
            zeroCounts[index] = zeroCounts[index - 1] + (S[index] == '0' ? 1 : 0);
        }

        // 分别是当前数字之前 '1' 的个数、当前节点之后 '0' 的个数、最少操作数（默认为把所有的0置为1所需的操作数）
        int oneBefore = 0, zeroAfter = 0, min = zeroCounts[S.Length - 1];
        for (int index = 0; index < S.Length; index++)
        {
            oneBefore = index + 1 - zeroCounts[index];
            zeroAfter = zeroCounts[S.Length - 1] - zeroCounts[index];
            min = Math.Min(min, oneBefore + zeroAfter);
        }

        return min;
    }
}
```