### 代码

```cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int n = (a | b) ^ c;
        int res = 0;
        while (n > 0) {
            int t = n & -n;
            if (t & c) {
                ++res;
            } else {
                if (a & t) ++res;
                if (b & t) ++res;
            }
            n ^= t;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/50468829d8f8964f4839a247c98d8fdcdacf10f7b2235f4c0aa1cdc7e4a2c524-image.png)
