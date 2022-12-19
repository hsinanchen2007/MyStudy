### 解题思路
利用map key-value第二遍遍历找到第一个出现一次的字符

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.size()==0) return ' ';
        map<char,int> mp;
        for(int i=0;i<s.size();++i)
        {
            //if(mp[s[i]]==0)//没出现过
              //  mp[s[i]]=1;
            //else
            ++mp[s[i]];
        }
        for(int i=0;i<s.size();++i)
        {
            if(mp[s[i]]==1) return s[i];
        }
        return ' ';

    }
};
```