### 解题思路
动态规划，使用字典的数组作为DP表；
dp[number][distance]=th; 表示number是以distance为步长的第th个等差数字；

### 代码

```csharp
public class Solution {
    public int LongestArithSeqLength(int[] A) {
        if (A.Length <= 2) return A.Length;
        var dp = new Dictionary<int, int>[A.Length];
        dp[0] = new Dictionary<int, int>();
        int max = 2;
        for (int index = 1; index < A.Length; index++)
        {
            dp[index] = new Dictionary<int, int>();
            for (int preIndex = 0; preIndex < index; preIndex++)
            {
                var distance = A[index] - A[preIndex];
                if (!dp[index].ContainsKey(distance))
                {
                    if (!dp[preIndex].ContainsKey(distance))
                    {
                        dp[preIndex].Add(distance, 1);
                    }

                    dp[index][distance] = dp[preIndex][distance] + 1;
                }
                else if (dp[preIndex].ContainsKey(distance))
                {
                    dp[index][distance] = Math.Max(dp[index][distance], dp[preIndex][distance] + 1);
                }

                max = Math.Max(max, dp[index][distance]);
            }
        }
        return max;
    }
}
```