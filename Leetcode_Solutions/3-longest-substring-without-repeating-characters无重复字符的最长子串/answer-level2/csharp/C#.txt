### 解题思路
1. 从第一个字符开始读取，放入临时的容器中，可以是List, HashSet, ...；
2. 如果遇到重复的字符，记录下此时的长度，并与之前记录的最大长度比较；
3. 从第二个字符开始读取，重复以上操作；


### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int maxlen = 0, tmplen = 0;
        byte[] charset = Encoding.Default.GetBytes(s);
        HashSet<byte> charlist = new HashSet<byte>();


        for (int i = 0; i < charset.Length; i++)
        {
            charlist.Clear();
            maxlen = GetMaxLen(ref charlist, charset[i], tmplen, maxlen);
            for (int j = i + 1; j < charset.Length; j++)
            {
                if (charlist.Contains(charset[j]))
                {
                    break;
                }
                maxlen = GetMaxLen(ref charlist, charset[j], tmplen, maxlen);
            }
        }
        return maxlen;
    }

    private int GetMaxLen(ref HashSet<byte> charlist, byte character, int tmplen, int maxlen)
    {
        charlist.Add(character);
        tmplen = charlist.Count;
        maxlen = Math.Max(tmplen, maxlen);
        return maxlen;
    }
}
```