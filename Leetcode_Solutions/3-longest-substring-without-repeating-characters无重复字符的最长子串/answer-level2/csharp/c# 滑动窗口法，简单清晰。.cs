执行用时：112 ms
```c#
public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int max = 0;
        int[] charTable = new int[256];

        int left = 0;
        for (int i = 0; i < s.Length; ++i)
        {
            if (charTable[s[i]] > left)
            {
                if (i - left > max) max = i - left;
                left = charTable[s[i]];
            }
            charTable[s[i]] = i + 1;
        }

        if (s.Length - left > max) max = s.Length - left;
        return max;
    }
}
```
c# 滑动窗口法，简单清晰。
charTable 是字符表，用来确定当重复发生的时候left的位置。