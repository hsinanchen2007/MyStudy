```c++
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> r(n, n);
        int t = -n;
        for (int i = 0; i < n; i++) {
            if (S[i] == C) t = i;
            r[i] = min(r[i], abs(t - i));
        }
        t = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (S[i] == C) t = i;
            r[i] = min(r[i], abs(t - i));
        }
        return r;
    }
};
```