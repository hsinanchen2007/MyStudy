**思路：**

直接根据题干公式 `T[n + 3] = T[n] + T[n + 1] + T[n + 2]` 进行递推即可。

数组可以直接简化为维护 3 个变量值，以达到 $O(1)$ 空间复杂度，但是本身输入空间就只有 37，所以也不是十分必要。

**代码：**
```python
class Solution:
    def tribonacci(self, n: int) -> int:
        ans = [0, 1, 1]
        if n < 3:
            return ans[n]
        for i in range(3, n + 1):
            ans.append(ans[i - 3] + ans[i - 2] + ans[i - 1])
        return ans[n]
```