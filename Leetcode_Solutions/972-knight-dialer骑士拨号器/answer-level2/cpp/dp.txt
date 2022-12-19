不是我写的啊啊啊，但是写的太好了，我就转载了


```
const int mod = 1e9 + 7;
class Solution {
public:
    int knightDialer(int N) {
        if (N == 1) return 10;
        vector<long> n(4, 1);
        vector<long> nn(4);
        for (int i = 1; i < N; ++i) {
            nn[0] = (n[3] << 1) % mod;
            nn[1] = (n[2] + n[3]) % mod;
            nn[2] = (n[1] << 1) % mod;
            nn[3] = ((n[1] << 1) + n[0]) % mod;
            swap(n, nn);
        }
        long res;
        res = (n[1] << 2) + n[0] + ((n[2] + n[3]) << 1);
        return res % mod;
    }
};
```
