### 解题思路
考虑使用哈希表，第一次扫描把字符串映射到hash表中的值加一，第二次便利字符对应的hash值，遇到的第一个值为一的字符即为正确结果。

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.empty()) return ' ';
        int len = s.size();

        unordered_map<char, int> m;
        for(int i = 0; i < len; ++i){
            m[s[i]] ++;
        }

        for(int i = 0; i < len; ++i){
            if(m[s[i]] == 1){
                return s[i];
            }
        }

        return ' ';

        
    }
};
```