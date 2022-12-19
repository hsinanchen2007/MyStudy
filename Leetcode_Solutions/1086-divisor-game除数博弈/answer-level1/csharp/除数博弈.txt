### 解题思路 
动态规划

### 代码

```csharp
public class Solution {
    public bool DivisorGame(int N)
        {
            bool[] result = new bool[N + 1];
            result[1] = false;

            for (int i = 1; i < result.Length; i++)
            {
                for (int j = 1; j < i; j++)
                {
                    if (i % j == 0 && result[i - j] == false)
                    {
                        result[i] = true;
                        break;
                    }
                }
            }

            return result[N];
        }
}
```