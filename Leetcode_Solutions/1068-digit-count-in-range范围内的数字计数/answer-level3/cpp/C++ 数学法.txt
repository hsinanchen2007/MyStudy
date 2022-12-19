思路可完全参考[数字 1 的个数](https://leetcode-cn.com/problems/number-of-digit-one/solution/shu-zi-1-de-ge-shu-by-leetcode/)
```
class Solution {
public:
    int min(int x, int y) {
        return (x < y) ? x : y;
    }
    int max(int x, int y) {
        return (x > y) ? x : y;
    }
    int digitsCount(int d, int low, int high) {
        if (low > 1)
            return digitsCount(d, 1, high) - digitsCount(d, 1, low - 1);
        long long pows = 1;
        int res = 0;
        while (high >= pows) {
            long long next_pows = pows * 10;
            res += (high / next_pows) * pows + min(max(high % next_pows - d * pows + 1, 0), pows);
            if (d == 0)
                res -= pows;
            pows = next_pows;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/670f44b2b498006376a7d4f0cbf9197490a476156f4bca1da8d64607cf2301ba-image.png)
