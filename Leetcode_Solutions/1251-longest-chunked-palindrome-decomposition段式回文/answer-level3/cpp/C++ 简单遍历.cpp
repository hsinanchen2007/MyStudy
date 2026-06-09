```C++ []
class Solution {
public:
    int longestDecomposition(string text) {
        int res = 0;
        int prev = 0;
        int S = text.size();
        for (int i = 0; i < S / 2; ++i) {
            if ((text.substr(prev, i - prev + 1)) == text.substr(S - 1 - i, i - prev + 1)) {
                res += 2;
                prev = i + 1;
            }
        }
        if (S % 2 == 1 || prev < S / 2)
            ++res;
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/4d3c89113af74316176e521258b0eff4ba2257f003a78d30e20ed46d9abd573d-image.png)

