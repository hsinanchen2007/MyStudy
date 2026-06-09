```
class Solution {
    int next[int(1e5 +50)];
public:
    string longestPrefix(string s) {
        for (int i = 0, j = next[0] = -1; i < s.size(); next[++i] = ++j) {
            while (~j && s[j] != s[i]) j = next[j];
        }
        return s.substr(0,next[s.size()]);
    }
};
```
