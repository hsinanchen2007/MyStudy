### 解题思路
C# 改良的滑动窗口

### 代码

```csharp
public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        if(string.IsNullOrEmpty(s1) ||
            string.IsNullOrEmpty(s2) ||
            s2.Length < s1.Length)
        {
            return false;
        }

        var s1Map = new int[26];
        var s2Map = new int[26];
        for(int index = 0; index < s1.Length; index++)
        {
            s1Map[(int)(s1[index]-'a')]++;
            s2Map[(int)(s2[index]-'a')]++;
        }
        for(int index = 0; index <= s2.Length - s1.Length; index ++)
        {
            if(CheckMap(s1Map, s2Map))
            {
                return true;
            }
            else
            {
                if(index + s1.Length < s2.Length)
                {
                    s2Map[(int)(s2[index]-'a')]--;
                    s2Map[(int)(s2[index + s1.Length]-'a')]++;
                }
            }
        }
        return false;
    }

    public bool CheckMap(int[] s1Map, int[] s2Map)
    {
        if(s1Map == null || s2Map == null || s1Map.Length != s2Map.Length)
        {
            return false;
        }

        for(int index = 0;index < s1Map.Length; index++)
        {
            if(s1Map[index]!=s2Map[index])
            {
                return false;
            }
        }
        return true;
    }
}
```