### 解题思路
2和3比较特殊，单独处理一下，然后就是采用递归，从2开始分别计算最大的值。
![image.png](https://pic.leetcode-cn.com/12c9689915c99c4f028067792e559fb1e38cded1f605a142de0c178334ef98f2-image.png)

### 代码

```python3
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1

        if n == 3:
            return 2

        cache_result = {}
        def _calc_multi(n):
            if n in cache_result:
                return cache_result[n]

            if n <= 3:
                cache_result[n] = n
                return n

            max_ret = max([i*_calc_multi(n-i) for i in range(2, n//2 + 1)])
            cache_result[n] = max_ret
            return max_ret

        return _calc_multi(n)

```