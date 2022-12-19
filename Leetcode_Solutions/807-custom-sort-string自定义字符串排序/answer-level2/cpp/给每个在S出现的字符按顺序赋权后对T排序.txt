老铁们，1min写完嗷
```c++
class Solution {
public:
  string customSortString(string S, string T) {
    vector<int> w(256, 100000);
    for (int i = 0; i < S.length(); i++) {
      w[S[i]] = i;
    }
    sort(T.begin(), T.end(), [&](const char x, const char y) {
      return w[x] < w[y];
    });
    return T;
  }
};
```