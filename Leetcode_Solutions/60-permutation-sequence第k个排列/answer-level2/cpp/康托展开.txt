```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string rst; rst.resize(n);
        if (n == 1) {
            rst[0] = static_cast<char>(k + '0');
            return rst;
        }

        vector<int> fact(n - 1); fact[0] = 1;
        for (int i = 1; i < n - 1; ++i) {
            fact[i] = fact[i - 1] * (i + 1);
        }

        --k;
        vector<int> mid(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            mid[i] = k / fact[n - 2 - i];
            k %= fact[n - 2 - i];
        }

        vector<bool> used(n, false);
        for (int i = 0; i < n - 1; ++i) {
            rst[i] = static_cast<char>(mid[i] + 1);
            for (int j = 1; j <= rst[i]; ++j) {
                if (used[j - 1]) ++rst[i];
            }
            used[rst[i] - 1] = true;
            rst[i] += '0';
        }
        
        for (int i = 0; i < n; ++i) {
            if (!used[i]) rst[n - 1] = '0' + i + 1;
        }

        return rst;
    }
};
```