### 思路

### 代码

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char, int> ump;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (auto c : t) ++ump[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--ump[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++ump[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};
```