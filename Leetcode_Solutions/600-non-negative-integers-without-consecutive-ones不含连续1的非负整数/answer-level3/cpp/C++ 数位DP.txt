### 解题思路
1，`k`记录当前考虑到第几位（从左往后数）
2，`limit`记录`k`左侧部分是否达到了数字的上界
3，`prev`记录`k`左侧相邻的数字是几（0或1）
然后利用记忆化深度优先搜索进行求解，也就是数位dp

### 代码

```cpp
class Solution {
public:
    int M[32][2][2];
    int D[32];
    int N;
    int dp(int k, int limit, int prev) {
        if (M[k][limit][prev] != -1) return M[k][limit][prev];
        if (k == N) return 1;
        M[k][limit][prev] = 0;
        for (int i = 0; i <= (limit ? D[k] : 1); ++i) {
            if (i == 1 && prev == 1) continue;
            M[k][limit][prev] += dp(k + 1, limit && (i == D[k]), i);
        }
        return M[k][limit][prev];
    }
    int findIntegers(int num) {
        memset(M, -1, sizeof(M));
        for (N = 0; num > 0; ++N, num >>= 1) {
            D[N] = num & 1;
        }
        reverse(D, D + N);
        return dp(0, 1, 0);
    }
};
```

![image.png](https://pic.leetcode-cn.com/30f84ad2aa7b7cb1f016ca02b54a7d28972b963a10ce7612420a65e9d5e0c3e4-image.png)
