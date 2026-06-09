```
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int m = (int)(sqrt(2 * N + 0.25) - 1.5);
        int res = 0;
        for (int i = 0; i <= m; ++i) {
            if ((2 * N - i * (i + 1)) % (2 * (i + 1)) == 0) {
                ++res;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/5986445f9376bf7bd6e8bee1c1b00cbe363dba2609ccdc1fc9334ebecb72240a-image.png)
