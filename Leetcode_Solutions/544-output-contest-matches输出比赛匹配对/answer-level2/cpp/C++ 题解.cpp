```C++ []
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            res.push_back(to_string(i));
        }
        for (; n > 1; n >>= 1) {
            int l = 0;
            int r = n - 1;
            while (l < r) {
                res[l] = "(" + res[l] + "," + res[r] + ")";
                ++l;
                --r;
            }
            res.resize(n >> 1);
        }
        return res[0];
    }
};
```

![image.png](https://pic.leetcode-cn.com/256d9b4fc3afcafd653633bb453f6215c315f4b18b50162fde5054c6f0bef32e-image.png)
