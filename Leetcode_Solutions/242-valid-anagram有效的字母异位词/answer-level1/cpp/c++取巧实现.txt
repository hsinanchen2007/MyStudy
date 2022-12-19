```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 先判断一下长度是否相等
        if(s.length()!=t.length())
            return false;
        int num[26] = {0};
        // 若s中出现第i个字母 num[i-1]++
        // 若t中出现第i个字母 num[i-1]--
        for(int i=0;i<s.length();i++)
        {
            num[s[i]-'a']++;
            num[t[i]-'a']--;
        }

        // 若s与t为字母异位词，结果应该都为0
        for(int i=0;i<26;i++)
            if(num[i]!=0)
                return false;
        return true;
    }
};
```
