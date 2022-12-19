## 思路
### 代码
```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {        
        for (int i = 0; i < t.size(); ++i) {
            if (s.find(s[i]) != t.find(t[i])) return false;
        }
        return true;
    }
};
```

