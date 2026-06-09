### 解题思路
这个就好比是最佳卖出股票时机一样。当L 和 R 相等的时候就相当于卖点。
本质就是贪心，一条道走到黑 就是 L和R相等

### 代码

```csharp
public class Solution {
    public int BalancedStringSplit(string s) {
        var maxCount = 0;
            var tmpCount = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i].Equals('R'))
                {
                    tmpCount++;
                }

                if (s[i].Equals('L'))
                {
                    tmpCount--;
                }

                if (tmpCount == 0)
                {
                    maxCount++;
                }
            }

            return maxCount;
    }
}
```