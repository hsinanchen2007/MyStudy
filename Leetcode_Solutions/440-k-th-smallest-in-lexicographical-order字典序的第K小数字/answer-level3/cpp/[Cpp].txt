### 解题思路
逐层的以各个数开头的数的数量，与k比较，比较过程中更新前缀和k。直到k为0

### 代码

```cpp
class Solution {
public:
    // 计算以now为前缀，数小于n的所有数的个数
    int helper(int n, long long now) {
        long long next = now + 1;
        int res = 0;
        while (now <= n) {
            res += min((long long)n + 1, next) - now;
            now *= 10;
            next *= 10;
        }
        return res;
    }

    int findKthNumber(int n, int k) {
        int res = 1;
        k--;
        while (k > 0) {
            // 计算前缀为res时，以res为前缀的数的数量
            int pre_nums = helper(n, res);
            // 如果以res为前缀的数大于k，则第k个数肯定以res开头，将res进一步精确扩展到下一层
            if (pre_nums > k) {
                res *= 10;
                // 原始的res已经被排除，因此为新前缀开始的第k-1个元素
                k--;
            } else {
                // 以res前缀的数量小于k时，第k个数应该以比res字典序更大的数开头
                // 此时排除掉所有res为前缀的数的数量
                res++;
                k -= pre_nums;
            }
        }
        return res;
    }
};
```