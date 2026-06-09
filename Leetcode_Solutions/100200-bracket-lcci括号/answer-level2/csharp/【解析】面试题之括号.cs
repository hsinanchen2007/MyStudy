### 解题思路
这道题用的是回溯的思想。当右括号数量不大于左括号时，若剩余的右括号数和左括号数都已为0，则将当前结果加入到结果列表中。若还剩下左括号，就将结果加上左括号，执行算法并回溯，若还剩下右括号，思路也相同。最后返回结果列表即可。

### 代码

```csharp
public class Solution {
    List<string> res = new List<string>();

    public void DFS(int l, int r, int restl, int restr, string curr) {
        if(r > l) {
            return;
        }

        if(restl == 0 && restr == 0) {
            res.Add(curr);
        }

        if(restl != 0) {
            curr += "(";
            DFS(l+1, r, restl-1, restr, curr);
            curr = curr.Substring(0, curr.Length-1);
        }

        if(restr != 0) {
            curr += ")";
            DFS(l, r+1, restl, restr-1, curr);
            curr = curr.Substring(0, curr.Length-1);
        }
    }

    public IList<string> GenerateParenthesis(int n) {
        DFS(1, 0, n-1, n, "(");
        return res;
    }
}
```