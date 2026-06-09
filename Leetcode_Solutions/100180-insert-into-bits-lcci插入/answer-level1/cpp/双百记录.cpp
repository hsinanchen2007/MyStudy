### 解题思路

![QQ截图20200327215134.png](https://pic.leetcode-cn.com/3ede52e5c99973627da2c41163dccb97440ef93425d2b1f008012ae6505dc257-QQ%E6%88%AA%E5%9B%BE20200327215134.png)

### 代码

```cpp
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        int res = 0;
        for (int k = i; k <= j; k ++) res += 1 << k;
        N |= res;
        for (int k = 0; k <= j - i; k ++)
            if (!(M >> k & 1)) N -= 1 << (i + k);
        return N;
    }
};
```