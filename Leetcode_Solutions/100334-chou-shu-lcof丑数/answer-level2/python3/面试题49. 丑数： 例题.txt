### 解题思路
一般来说，没刷过肯定只能暴力了。

### 代码

```python []
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ans, i, j, k = [1], 0, 0, 0
        for _ in range(n - 1):
            ans.append(min(ans[i] * 2, ans[j] * 3, ans[k] * 5))
            i += ans[-1] == ans[i] * 2
            j += ans[-1] == ans[j] * 3
            k += ans[-1] == ans[k] * 5
        return ans[-1]
```