### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        str += ' ';
        unordered_map<string, char> map; 
        unordered_map<char, string> map2; 
        string t = "";
        int i = 0, j = 0;
        for(;i < str.size() && j < pattern.size();++i){
            if(str[i] != ' ') t += str[i];
            else {
                if(map.count(t) == 0 && map2.count(pattern[j]) == 0){
                    map[t] = pattern[j];
                    map2[pattern[j]] = t;
                }
                else if(map.count(t) || map2.count(pattern[j])){
                    if(map.count(t) && map[t] != pattern[j])return false;
                    if(map2.count(pattern[j]) && map2[pattern[j]] != t)return false;
                }
                t = "";
                ++j;
            }
        }
        if(i != str.size() || j != pattern.size())return false;
        return true;
    }
};
```