### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, int> map_s;
        unordered_map <char, int> map_t;
        int length = s.size();
        for(int i = 0; i < length; ++ i)
        {
            if(map_s[s[i]] != map_t[t[i]]) return false;
            else if(map_s[s[i]] == 0)  // 修改过则不在处理
            {
                map_s[s[i]] = i + 1;
                map_t[t[i]] = i + 1;
            }
        } 
        return true;
    }
};
```