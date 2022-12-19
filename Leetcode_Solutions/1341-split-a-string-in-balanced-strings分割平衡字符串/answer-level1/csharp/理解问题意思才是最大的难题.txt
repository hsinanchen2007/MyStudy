### 解题思路
分解的字符串必须要两者数量相同即可，剩下的阶梯思路用栈来解决十分方便，易于统计。

### 代码

```csharp
public class Solution {
    public int BalancedStringSplit(string s) {
        int b = 0;
        Stack<char> a = new Stack<char>();
        for(int i = 0;i < s.Length;i++)
        {
            if(a.Count == 0 || a.Peek() == s[i]){
                a.Push(s[i]);
            }else{
                a.Pop();
            }
            if(a.Count == 0){
                b++;
            } 
        }
        return b;
    }
}
```