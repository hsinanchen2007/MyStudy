### 解题思路
此处撰写解题思路
  
### 代码

```csharp
//using System.Collections.Generic;
public class Solution {
    public bool IsValid(string s) {
        if (s.Length == 0) return true;
        if (s.Length % 2 != 0) return false;
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        
        Stack<int> sta = new Stack<int>();

        foreach (var item in s)
        {
            if (item == '(' || item == '[' || item == '{')
                sta.Push(item);
            else if (sta.Count == 0 || sta.Peek() + (sta.Peek() == '(' ? 1 : 2) != item)
                return false;
            else
                sta.Pop();
        }

        return sta.Count == 0;
    }
}
```