```c++
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> v(n + 1, 0);
        int l = 0, r = n;
        for (int i = 0; i < n; i++) {
            if (S[i] == 'I') v[i] = l++;
            if (S[i] == 'D') v[i] = r--;
        }
        v[n] = l;
        return v;
    }
};
```