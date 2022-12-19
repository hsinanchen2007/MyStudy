1. 首先排序
2. ！！！要注意负数情况
例如 [-14, -3, 1, 2, 3]
前两个 * 后一个 vs 后三个

```
L = sorted(nums)
  n = len(nums)
  if n < 3:
    return False
  a = L[n - 1] * L[n - 2] * L[n - 3]
  b = L[0] * L[1] * L[n - 1]
  # 判断 最前面和最后面对比, 因为会有负数
  return max(a, b)
```
