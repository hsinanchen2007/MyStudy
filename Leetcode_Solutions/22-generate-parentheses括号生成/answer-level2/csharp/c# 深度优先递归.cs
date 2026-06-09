### 解题思路
首先，正确字符串一定以左括号‘（’开头，且只有以下三种情况会继续向后延伸：
`1、左括号数>右括号数，且左括号数==n`
`2、左括号数>右括号数，且左括号数<n`
`3、左括号数==右括号数，且左括号数<n`
而一旦达成下面条件，便说明字符串已经拼接完成且正确
`左括号数==右括号数，且左括号数==n`
根据以上思路，递归分支已经确定，再需要做的就是返回上一层时，需要把当前层添加的字符串移除即可
### 代码

```csharp
public class Solution {
    public IList<string> GenerateParenthesis(int n) {
            List<string> result = new List<string>();
            StringBuilder sb = new StringBuilder();
            void GetNext(int l, int r)
            {
                //l>r   l==n
                //l>r   l<n
                //l==r  l<n
                //l==r  l==n
                if (l > r && l == n)
                {
                    sb.Append(')');
                    GetNext(l, r + 1);
                }
                else if (l > r && l < n)
                {
                    sb.Append('(');
                    GetNext(l + 1, r);
                    sb.Append(')');
                    GetNext(l, r + 1);
                }
                else if (l == r && l < n)
                {
                    sb.Append('(');
                    GetNext(l + 1, r);
                }
                else if (l == r && l == n)
                {
                    result.Add(sb.ToString());
                }
                sb.Remove(sb.Length - 1, 1);
            }
            sb.Append('(');
            GetNext(1, 0);
            return result;
    }
}
```