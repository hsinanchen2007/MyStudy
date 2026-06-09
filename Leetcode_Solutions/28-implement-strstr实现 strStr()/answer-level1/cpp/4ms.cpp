```
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (needle.length() == 0)
            return 0;
        for (int i = 0, j = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[j])
            {
                j++;
                if (j == needle.length())
                {
                    return i - j + 1;
                }
            }
            else if (haystack[i] != needle[j])
            {
                i = i - j;
                j = 0;
            }
        }
        return -1;
    }
};
```
