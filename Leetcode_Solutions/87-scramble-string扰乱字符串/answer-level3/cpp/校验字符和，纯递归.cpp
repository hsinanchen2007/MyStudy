### 解题思路
此处撰写解题思路
校验字符和。
### 代码

```cpp
class Solution {
public:
    bool isSc(string s1, string s2)
    {
        if(s1.length() != s2.length()) return false;
        int tl = s1.length();
        if(tl==1)
        {
            if(s1[0] == s2[0]) return true;
            return false;
        }
        int cs1;
        int cs2s,cs2e;
        cs1 = 0;
        cs2s = 0;
        cs2e = 0;
        for(int i=1;i<tl;++i)
        {
            cs1 = cs1 + s1[i-1];
            cs2s = cs2s + s2[i-1];
            cs2e = cs2e + s2[tl-i];
            if(cs1 == cs2s && isSc(s1.substr(0,i),s2.substr(0,i)) && isSc(s1.substr(i,tl-i),s2.substr(i,tl-i))) return true;
            if(cs1 == cs2e && isSc(s1.substr(0,i),s2.substr(tl-i,i)) && isSc(s1.substr(i,tl-i),s2.substr(0,tl-i))) return true;
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        return isSc(s1,s2);        
    }
};
```