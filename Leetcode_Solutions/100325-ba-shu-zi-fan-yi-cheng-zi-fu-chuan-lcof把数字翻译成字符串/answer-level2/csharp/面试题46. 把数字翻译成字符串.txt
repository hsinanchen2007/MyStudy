### 解题思路
C# 动态规划

### 代码

```csharp
public class Solution {
    public int TranslateNum(int num) {
        var number = num.ToString();
        var cache = new int[number.Length + 1];
        cache[0] = 1;
        cache[1] = 1;
        for (int index = 2; index <= number.Length; index++)
        {
            var nextValue = (number[number.Length - index] - '0') * 10 + (number[number.Length - index + 1] - '0');
            var canMinusTwo = 10 <= nextValue && nextValue <= 25;
            cache[index] = cache[index - 1] + cache[index - 2] * (canMinusTwo ? 1 : 0);
        }

        return cache[number.Length];
    }
}
```