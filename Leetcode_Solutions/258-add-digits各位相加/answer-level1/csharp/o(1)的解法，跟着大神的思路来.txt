### 解题思路
核心是m* 10^n/9=9* C+m，理解这个即可

### 代码

```csharp
public class Solution {
    public int AddDigits(int num) {
        if (num < 10)
            {
                return num;
            }
            else
            {
                if (num % 9 == 0)
                {
                    return 9;
                }
                else
                {
                    return num % 9;
                }
            }
    }
}
```