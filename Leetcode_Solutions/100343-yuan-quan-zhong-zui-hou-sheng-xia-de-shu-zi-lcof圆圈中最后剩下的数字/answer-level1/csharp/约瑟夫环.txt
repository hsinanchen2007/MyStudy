### 解题思路
之前不知道约瑟夫环公式，学到了学到了

### 代码

```csharp
public class Solution {
    public int LastRemaining(int n, int m) {
        int p = 0;
        for(int i = 2; i <= n; i++)
        {
            p = (p+m)%i;
        }
        return p;

    }
}
```