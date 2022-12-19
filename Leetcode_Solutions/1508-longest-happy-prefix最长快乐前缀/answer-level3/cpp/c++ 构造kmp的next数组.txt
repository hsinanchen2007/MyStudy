```
class Solution {
 public:
  string longestPrefix(string s) {
    int n = s.size();
    vector<int> next(n);
    next[0] = -1;
    for (int i = 1; i < n; ++i) {
      int j = next[i - 1];
      for (;;) {
        if (s[j + 1] == s[i]) {
          next[i] = j + 1;
          break;
        }
        if (j == -1) {
          next[i] = -1;
          break;
        }
        j = next[j];
      }
    }
    return next[n - 1] == -1 ? "" : s.substr(0, next[n - 1] + 1);
  }
};
```
