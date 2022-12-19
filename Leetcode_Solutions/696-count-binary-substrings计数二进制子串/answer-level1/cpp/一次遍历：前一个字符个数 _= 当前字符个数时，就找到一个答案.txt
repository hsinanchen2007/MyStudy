```
class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int pre = 0;    // 前一个字符出现的次数
        int cur = 1;    // 当前的字符出现的次数
        int ans = 0;    // 满足要求的子串的个数
        for(int i = 0; i < s.length()-1; ++i) 
        {
            if(s[i] == s[i+1]) 
            {
                ++cur;
            }
            else               
            {
                pre = cur; 
                cur = 1;
            }
            // 前一个字符个数 >= 当前字符个数时，就找到一个答案
            if (pre >= cur) 
            {
                ++ans;
            }
        }
        return ans;
    }
};
```