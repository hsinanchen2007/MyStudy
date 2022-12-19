### 解题思路
Substring 的 第二个 s 居然不大写
### 代码

```csharp
public class Solution {
    public string ReverseWords(string s) {
        var res = new StringBuilder();
        foreach(var i in s.Split(" ")){
            var tmp = i.ToCharArray();
            Array.Reverse(tmp);
            res.Append(new String(tmp)+" ");
        }
        var r = res.ToString();
        return r.Substring(0,r.Length-1);
    }
}
```