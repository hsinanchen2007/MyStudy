### 解题思路
偷懒使用try...catch解决最短字符串的情况。嘛，其实有个优化的点，就是foreach的部分，strs[0]其实和自己比了一次（完全木有意义……只是因为foreach看起来易懂……嘛

### 代码

```csharp
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
            int longnum = -1;

            if (strs.Length == 0)
                return "";
            try
            {
                while (true)
                {
                    var chr = strs[0][longnum + 1];
                    foreach (string s in strs)
                    {
                        if (s[longnum + 1] != chr)
                            return longnum == -1 ? "" : strs[0].Substring(0, longnum + 1);
                    }
                    longnum += 1;
                }
            }
            catch { return longnum == -1 ? "" : strs[0].Substring(0, longnum + 1); }
    }
}
```