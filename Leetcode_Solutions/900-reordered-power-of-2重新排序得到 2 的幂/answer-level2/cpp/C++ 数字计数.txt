```
class Solution {
public:
    int digitLen(int n) {
        int res = 0;
        while (n > 0) {
            ++res;
            n /= 10;
        }
        return res;
    }
    vector<int> digits(int n) {
        vector<int> res(10);
        while (n > 0) {
            ++res[n % 10];
            n /= 10;
        }
        return res;
    }
    vector<set<vector<int> > > M;
    Solution() {
        M.resize(12);
        for (int i = 0; i < 32; ++i) {
            int t = 1 << i;
            M[digitLen(t)].insert(digits(t));
        }
    }
    bool reorderedPowerOf2(int N) {
        int S = digitLen(N);
        vector<int> b = digits(N);
        return M[S].count(b) > 0;
    }
};
```
![image.png](https://pic.leetcode-cn.com/06461c31cce628e819959e171ef9b2116d348fe7e33cf5863a88699dda4c24a3-image.png)
