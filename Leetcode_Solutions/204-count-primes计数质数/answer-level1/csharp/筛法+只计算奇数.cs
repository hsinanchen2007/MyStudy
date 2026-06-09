### 解题思路
总所周知偶数不是质数（2除外）

### 代码

```csharp
public class Solution {
    public int CountPrimes(int x) {
        int count = 1;
        bool[] dp = new bool[x];
        for (int i = 3; i < x; i += 2)
            if (!dp[i]){
                count++;
                for (int j = i * 3; j < x; j += i << 1)
                    dp[j] = true;
            }
        return x > 2 ? count : 0;
    }
}
```