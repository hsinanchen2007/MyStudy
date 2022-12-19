### 解题思路
我们首先特判两种情况，即给定的字符串长度为0和长度为1时，返回值即为给定字符串的长度。除此之外，无重复字符的最长字串长度len最小为1，我们可以先设置i，j均为0，将第i位到第j位看作最长字串，看第j+1位是否在最长子串中，如果第k位和第j+1位相同，设置i=k+1。无论如何，我们都将j++。因为当第k位与第j+1位相同时，第n（n>=i&&n<=k）位到第j+1位中必定有重复的字符，即第k位与第j+1位相同。然后，我们将len与j-i+1比大小，将其中较大的赋值给无重复字符的最长字符串长度len。如此循环到字符串结尾。返回无重复字符的最长字符串长度len。

### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int len = 1, i = 0, j = 0, k;
        if (s.Length < 2)
            return s.Length;
        while(j + 1 < s.Length)
        {
            for(k = i; k <= j; k++)
            {
                if(s[j + 1] == s[k])
                {
                    break;
                }
            }
            if(k <= j)
            {
                i = 1 + k;
            }
            j++;
            if (len < j - i + 1)
                len = j - i + 1;
        }
        return len;
    }
}
```