
```
class Solution {
public:
    int numTrees(int n) {
        if(n < 1) return 0;
        return _catalan(n);
    }

private:
    using ll = long long;

    // C(n) = C(n-1) * (4 * n - 2) / (n + 1)
    // C(1) = 1
    int _catalan(int n)
    {
        if(n == 1) return 1;
        int result = 1;
        for(int k = 2; k <= n; ++k)
            result = result * (ll)(k * 4 - 2) / (k + 1);
        return result;
    }
};

```