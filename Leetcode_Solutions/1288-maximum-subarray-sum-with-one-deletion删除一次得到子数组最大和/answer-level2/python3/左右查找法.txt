- 思路较为简单
- 设计两个数组，left和right，
  - left 统计从0到当前位置最大的和值
  - right统计从最后位置到当前位置的最大和值
- 结果值从下面的情况中寻找：
  - 左面最大，不含当前值
  - 右面最大，不含当前值
  - 左面最大，含当前值
  - 右面最大，含当前值
  - 左面最大加右面最大，不含当前值
  - 左面最大加右面最大，含当前值

```python
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        length = len(arr)

        left = [0] * length
        right = [0] * length

        left[0] = arr[0]
        right[-1] = arr[-1]

        for i in range(1, length):
            left[i] = max(left[i - 1] + arr[i], arr[i])
            right[length - i - 1] = max(right[length - i] + arr[length - i - 1], arr[length - i - 1])

        n_inf = float('-inf')
        res = n_inf
        for i in range(length):
            left_val = left[i - 1] if i > 0 else n_inf
            right_val = right[i + 1] if i < length - 1 else n_inf

            res = max(res, left_val, right_val, left_val + right_val, left[i], right[i], left[i] + right[i] - arr[i])
        return res
```


