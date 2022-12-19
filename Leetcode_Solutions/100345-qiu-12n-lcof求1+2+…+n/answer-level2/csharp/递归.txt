### 解题思路
递归法

### 代码

```csharp
public class Solution {
    public int SumNums(int n) {
        if(n == 1)
        {
            return 1;
        }

        return n + SumNums(n-1);
    }
}
```