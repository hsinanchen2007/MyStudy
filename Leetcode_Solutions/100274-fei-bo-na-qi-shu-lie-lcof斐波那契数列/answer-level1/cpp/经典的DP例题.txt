
```cpp
const int mod = 1e9 + 7;
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int f[n + 1];
        memset(f,0,sizeof f);
        f[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            f[i] = f[i - 1] + f[i - 2];
            if (f[i] >= mod) f[i] -= mod;
        }
        return f[n];
    }
};
```