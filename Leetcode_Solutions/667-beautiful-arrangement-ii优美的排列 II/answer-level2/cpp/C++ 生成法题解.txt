```C++ []
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n, 0);
        res[0] = 1;
        int i = 1;
        int t = 1;
        for (int j = k; j > 0; --j) {
            if (t) {
                res[i] = res[i - 1] + j;
            } else {
                res[i] = res[i - 1] - j;
            }
            ++i;
            t ^= 1;
        }
        ++k;
        for (; i < n; ++i) {
            res[i] = ++k;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/61aa118bb63566146f0351f141e6f481d65063da5bf100c841537d332af4cd06-image.png)
