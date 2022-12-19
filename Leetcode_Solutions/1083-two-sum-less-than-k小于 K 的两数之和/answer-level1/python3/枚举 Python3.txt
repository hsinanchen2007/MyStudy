**思路：**

由于数组的长度范围只有`100`，所以暴力枚举即可。每次枚举数组中两个不同的数，先判断这两个数的和是否小于`K`：如果大于等于`K`，则跳过；如果小于`K`，则继续比较和`K`的差值是否小于当前答案，如果差值更小，则更新答案。设初始答案为`ans = -1`，程序结束返回`ans`即可。

**代码：**

```python
class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        n = len(A)
        ans = -1
        for i in range(n - 1):
            for j in range(i + 1, n):
                if A[i] + A[j] < K and K - A[i] - A[j] < K - ans:
                    ans = A[i] + A[j]
        return ans
```

