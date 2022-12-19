### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.size() == 0)return ' ';
        unordered_map<char, int> um;
        for(auto c : s)
        {
            if(um.find(c) != um.end())
                um[c]++;
            else
                um[c] = 1;
        }
        for(auto c : s)
        {
            if(um[c] == 1)
                return c;
        }
        return ' ';
    }
};
```