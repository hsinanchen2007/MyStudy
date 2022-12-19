### 解题思路
参考得来的结果，本来想用字典记录char,index  通过更改index值来处理，结果中间出现错乱，如果哪位这样处理，可以发我我参考参考
因为需要的是连续的数据，所以遇到重复，只需要将重复的字符及之前的字符都remove就好了，后续的在进行计算其他长度
也可以判断一下当前长度和剩余字符长度的差，如果当前长度已经大于剩余字符的总长度，则没有必要在进行下去了，但是我加上之后，耗时更久了，所以那部分代码就不贴了，如有更好方案，评论即可

### 代码

```csharp
public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        List<char> ls = new List<char>();
        var maxLength = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (ls.Contains(s[i]))
            {
                ls.RemoveRange(0, ls.IndexOf(s[i]) + 1);
            }
            ls.Add(s[i]);
            if (ls.Count > maxLength)
            {
                maxLength = ls.Count;
            }
        }
        return maxLength;
    }
}
```