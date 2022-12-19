```
class Solution {
public:
    int maximumNumberOfOnes(int m, int n, int len, int x) {
        int ret = (m / len) * (n / len) * x;
        vector<vector<int>> cnt(n, vector<int>(m));
        for (int i = 0; i < n % len; ++i) {
            for (int j = 0; j < m % len; ++j) {
                cnt[i][j]++;
            }
        }
        for (int i = 0; i < n % len; ++i) {
            for (int j = 0; j < len; ++j) {
                cnt[i][j] += m / len;
            }
        }
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < m % len; ++j) {
                cnt[i][j] += n / len;
            }
        }
        vector<int> a;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                a.push_back(cnt[i][j]);
            }
        }

        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < x; ++i) {
            if (a[i] == 0) break;
            ret += a[i];
        }
        return ret;
    }
};
```