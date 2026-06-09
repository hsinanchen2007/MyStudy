```cpp
class Solution {
public:
    int uniqueLetterString(const string &S) {
        int res = 0;
        int n = S.size();
        int cur = 0;
        int M = 1e9 + 7;
        vector<int> first(26);
        vector<int> second(26);
        for (auto i = 0; i < n; ++i) {
            int c = S[i] - 'A';
            cur = cur + 1 + i - first[c] * 2 + second[c];
            res = (res + cur) % M;
            second[c] = first[c];
            first[c] = i + 1;
        }
        return res;
    }
};
```
