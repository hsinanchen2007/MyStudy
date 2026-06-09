### 解题思路
遍历替换

### 代码

```csharp
public class Solution {
    public int MinAddToMakeValid(string S) {
        string unit="()";
        while(S.Contains(unit))
            S=S.Replace("()","");
        return S.Length;
    }
}
```