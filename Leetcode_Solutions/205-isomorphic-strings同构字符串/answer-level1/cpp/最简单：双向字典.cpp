```
class Solution {
public:
    // 按字符串顺序，建立一对一映射关系：map<s, t> 和 map<t, s>
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char, char> std, tsd;
        for(int i=0;i<s.length();i++)
        {
            char c1 = s[i], c2 = t[i];
            if(std.find(c1) == std.end() && tsd.find(c2) == tsd.end())
            {
                std[c1] = c2;
                tsd[c2] = c1;
            }
            else
            {
                if(std[c1] != c2 || tsd[c2] != c1) return false;
            }
        }
        
        return true;
    }
};
```