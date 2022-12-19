### 解题思路
利用计算

### 代码

```csharp
public class Solution {
    public bool IsPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int mark = 0;
        while(x > mark)
        {
            mark = mark * 10 + x % 10;
            x /=10;
        }
        return x == mark || x == mark / 10;
    }
}
```