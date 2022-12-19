### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<char> sHash=vector<char>(300,'0'),tHash=sHash;

    bool isIsomorphic(string s, string t) 
    {
        for(int i=0;i<s.size();i++)
            if(!Hash(s[i],t[i])) return false;
        
        return true;
    }

    bool Hash(char s,char t)
    {
        if(sHash[s]=='0' && tHash[t]=='0')
        {
            sHash[s]=t;
            tHash[t]=s;
            return true;
        }

        if(sHash[s]==t && tHash[t]==s) return true;
        else return false;
    }
};
```