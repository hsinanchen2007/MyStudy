### 解题思路
投机取巧 正则表达式

### 代码

```csharp
using System.Text.RegularExpressions;

public class Solution {
    public bool IsNumber(string s) {
        if (string.IsNullOrWhiteSpace(s)) return false;
        var regex = new Regex(@"^\s*(-|\+)?(\d+|\d+\.\d*|\d*\.\d+)(E(-|\+)?\d+)?\s*$",
            RegexOptions.IgnoreCase | RegexOptions.Singleline | RegexOptions.Compiled);
        return regex.IsMatch(s);
    }
}
```