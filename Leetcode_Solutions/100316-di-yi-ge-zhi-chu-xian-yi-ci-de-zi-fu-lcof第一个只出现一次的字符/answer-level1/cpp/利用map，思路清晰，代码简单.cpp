```
class Solution {
public:
    char firstUniqChar(string s) {
        if(s == "")
            return ' ';
        //map中是对应字符出现的次数
        unordered_map<char,int> cmap;
        for(auto i = 0;i < s.size();i++)
        {
            cmap[s[i]]++;
        }
        //按字符串的顺序在map中查找到第一个出现一次的字符
        for(auto i = 0;i < s.size();i++)
        {
            if(cmap[s[i]] == 1)
                return s[i];
        }
        //没有找到
        return ' ';
    }
};
```
