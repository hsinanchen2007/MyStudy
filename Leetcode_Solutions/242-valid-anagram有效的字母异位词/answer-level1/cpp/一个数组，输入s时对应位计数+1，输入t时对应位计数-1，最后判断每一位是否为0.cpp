### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> temp(26, 0);  //小写字母a对应的ascii码为97
        for(size_t i = 0; i < s.size(); ++i)
        {
            temp[s[i]-'a'] += 1;
        }
        for(size_t i = 0; i < t.size(); ++i)
        {
            temp[t[i]-'a'] -= 1;
        }
        for(auto c : temp)
        {
            if(c != 0)return false;
        }
        return true;
    }
};
```