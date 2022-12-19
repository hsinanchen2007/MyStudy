### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        map<char, int> mp;
        for (auto s : s1) mp[s]++;
        for (auto s : s2) {
            if (!mp[s]) return false;
            mp[s]--;
        }
        for (auto t : mp) if (t.second) return false;
        return true;
    }
};
```