### 解题思路
循环-分割-翻转-组合
### 代码

```csharp
public class Solution {
    public string ReverseWords(string s) {
        string[] n=s.Split(" ");
        for(int i=0;i<n.Length;i++)
        {
            n[i]=Reverse(n[i]);
        }
        return string.Join(" ",n);
    }
    public string Reverse(string s)
    {
        char[] arr = s.ToCharArray();
        Array.Reverse(arr);
        return new string(arr);
    }
}
```