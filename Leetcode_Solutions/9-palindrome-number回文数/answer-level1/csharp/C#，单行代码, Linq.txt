### 解题思路
终于不是python的单行代码啦～Linq真优雅

### 代码

```csharp
public class Solution {
    public bool IsPalindrome(int x) {
        return x.ToString() == new String(x.ToString().Reverse().ToArray());
    }
}
```