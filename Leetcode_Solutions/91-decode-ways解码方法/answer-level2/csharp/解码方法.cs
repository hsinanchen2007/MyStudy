### 解题思路1
mark下刷题中的代码快照。思路就是找到确认是否是动态规划类问题，然后找出递推公式，然后coding。显然这段代码太冗长...
### 代码

```csharp
public class Solution {
     public int NumDecodings(string s)
        {
            int[] result = new int[s.Length];
            for (int i = 0; i < result.Length; i++)
            {
                if (i == 0)
                {
                    if (IsPassEncode(s[i].ToString()))
                    {
                        result[i] = 1;
                    }
                    else
                    {
                        result[i] = 0;
                    }
                }
                else if (i == 1)
                {
                    if (result[i - 1] == 0)
                    {
                        result[i] = 0;
                    }
                    else
                    {
                        if (IsPassEncode(s[i].ToString()))
                        {
                            if (IsPassEncode(s.Substring(i - 1, 2)))
                            {
                                result[i] = 2;
                            }
                            else
                            {
                                result[i] = 1;
                            }
                        }
                        else
                        {
                            if (IsPassEncode(s.Substring(i - 1, 2)))
                            {
                                result[i] = 1;
                            }
                            else
                            {
                                result[i] = 0;
                            }
                        }
                    }
                }
                else
                {
                    if (IsPassEncode(s[i].ToString()))
                    {
                        result[i] = result[i - 1] + (s[i - 1] != '0' && int.Parse(s.Substring(i - 1, 2)) <= 26 ? result[i - 2] : 0);
                    }
                    else
                    {
                        result[i] = (s[i - 1] != '0' && int.Parse(s.Substring(i - 1, 2)) <= 26 ? result[i - 2] : 0);
                    }
                }
            }
            return result.Last();
        }

        private bool IsPassEncode(string v)
        {
            if (int.Parse(v) > 0 && int.Parse(v) <= 26)
            {
                return true;
            }
            return false;
        }
}
```