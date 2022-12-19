### 解题思路
求全路径的就往回溯法代码模板上套吧

### 代码

```csharp
public class Solution {
    public IList<string> GenerateParenthesis(int n)
    {
        var result = new List<string>();
        var current = new List<char>();
        Backtrack(n, n, current, result);
        return result;
    }

    public void Backtrack(int openCount, int closeCount, List<char> current, List<string> result)
    {
        if (closeCount == 0)
        {
            result.Add(new string(current.ToArray()));
            return;
        }

        if (openCount > 0)
        {
            current.Add('(');
            Backtrack(openCount - 1, closeCount, current, result);
            current.RemoveAt(current.Count - 1);
        }
        if (closeCount > openCount)
        {
            current.Add(')');
            Backtrack(openCount, closeCount - 1, current, result);
            current.RemoveAt(current.Count - 1);
        }
    }
}
```