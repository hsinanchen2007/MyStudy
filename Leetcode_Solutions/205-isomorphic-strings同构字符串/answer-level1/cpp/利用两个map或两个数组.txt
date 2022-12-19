### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1;
        unordered_map<char,char> m2;

        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m1.find(s[i]) == m1.end()) {
                if(m2.find(t[i]) != m2.end()) {
                    return false;
                }
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            } else {
                if(m1[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;       
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }
        int map[256] = {0};
        memset(map, -1, sizeof(map));

        bool mapped[256];
        memset(mapped, false, sizeof(mapped));

        for (int i = 0; i < s.size(); i++) {
            if(map[s[i]] == -1) {
                if(mapped[t[i]])
                    return false;
                map[s[i]] = t[i];
                mapped[t[i]] = true;
            }
            else if (map[s[i]] != t[i]) {
                return false;
            }
        }
        return true;       
    }
};
```