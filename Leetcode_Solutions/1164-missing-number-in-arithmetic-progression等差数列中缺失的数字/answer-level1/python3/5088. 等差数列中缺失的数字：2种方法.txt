方法一：

通过首项末项和总数求得差值，然后遍历一遍，如果差值不对就输出。

```python []
class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        delta = (arr[-1] - arr[0]) // len(arr)
        for i in range(1, len(arr)):
            if arr[i] - arr[i - 1] != delta:
                return arr[i] - delta
```

方法二：

通过求和公式求出总值，然后减去直接求和的总值，即可得出缺失项。

```python []
class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        return (arr[0] + arr[-1]) * (len(arr) + 1) // 2 - sum(arr)
```

56ms仅供参考。