### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int cond_flag = 0;
        if (s.empty())
        {
            return "";
        }
        if (s.size() == 2 && s[0] == s[1])
        {
            return s;
        }
        if(s.size() == 3 && s[0] == s[2])
        {
            return s;
        }
        if(s.size() == 4 && s[0] == s[3] && s[1] == s[2])
        {
            return s;
        }
        int maxlen = 1;
        int pos1 = 0, pos2 = 0;
        for (int i = 1; i < s.size(); i++)
        {
            //发现回文子串aa
            if (s[i] == s[i - 1])
            {
                int posforward = i-1;
                int posback = i;
                while (posforward >= 0 && posback <= s.size() - 1)
                {
                    if (s[posforward] != s[posback])
                    {
                        //说明回文到头了，回文字串位置就是s[posforward+1,posback-1]
                        int tmplen = posback - 1 - posforward;
                        if (tmplen > maxlen)
                        {
                            maxlen = tmplen;
                            pos1 = posforward + 1;
                            pos2 = posback - 1;
                        }
                        break;
                    }
                    else
                    {
                        int tmplen = posback - posforward+1;
                        if (tmplen > maxlen)
                        {
                            maxlen = tmplen;
                            pos1 = posforward;
                            pos2 = posback;
                        }
                        posforward--;
                        posback++;
                    }
                }
            }
            //发现回文子串aba
            if (s[i - 1] == s[i + 1])
            {
                int posforward = i - 1;
                int posback = i + 1;
                while (posforward >= 0 && posback <= s.size() - 1)
                {
                    if (s[posforward] != s[posback])
                    {
                        //说明回文到头了，回文字串位置就是s[posforward+1,posback-1]
                        int tmplen = posback - 1 - posforward;
                        if (tmplen > maxlen)
                        {
                            maxlen = tmplen;
                            pos1 = posforward + 1;
                            pos2 = posback - 1;
                        }
                        break;
                    }
                    else
                    {
                        int tmplen = posback - posforward+1;
                        if (tmplen > maxlen)
                        {
                            maxlen = tmplen;
                            pos1 = posforward;
                            pos2 = posback;
                        }
                        posforward--;
                        posback++;
                    }
                }

            }
        }
        return s.substr(pos1, maxlen);
    }
};
```

很naive的方法。思路是遍历一遍，然后从当前字母往两边查找，直到不再是回文子串为止。不过需要注意的是，回文的中心有两种可能（有可能同一个位置出现两种），即baab和bab两种可能，取最长即可。