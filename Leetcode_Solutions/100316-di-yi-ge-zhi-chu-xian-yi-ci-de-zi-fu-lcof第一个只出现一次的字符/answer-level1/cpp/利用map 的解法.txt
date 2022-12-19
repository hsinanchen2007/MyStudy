### 解题思路
//见代码

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        map<char,int> temmap;
        for(int i = 0;i < s.size();i++)
        {
            temmap[s[i]]++;
        }
        for(int i = 0;i < s.size();i++)
        {
            if(temmap[s[i]] == 1)
                return s[i];
        }
        return ' ';
    }
};
```