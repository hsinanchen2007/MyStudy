![image.png](https://pic.leetcode-cn.com/cad850d0c4aa6b6fe304504fe89f27aade8bb0faa2631b4da7a2fbd30b04654d-image.png)

### 解题思路
限定了只能向下或者向右，那么一共步数就是（m+n-2）步；
其中有m-1步是向右，是个组合问题（在m+n-2个bit中中选出m-1个位置为1，其余为0）。结果就是C(m+n-2)(m-1).

### 代码

```cpp
// c(m+n-2)(m-1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)
            return 0;

        int total = m + n - 2;
        int need = min(m,n) - 1;
        return c_m_n_calfunc(total, need);
    }

    unsigned long c_m_n_calfunc(unsigned long m, unsigned long n)
    {
        if(0 == n)
            return 1;
            
        unsigned long res = m;
        unsigned long src_n = n;
        for(;n > 1; --n)
        {
            --m;
            res = res * m;
        }

        for(n = src_n; n > 1; --n)
        {
            res = res / n;
        }

        return res;
    }
};
```