### 快排

用列表解析来比较

```python []
class Solution:
    def subSort(self, array: List[int]) -> List[int]:
        sortedarray = sorted(array)
        a = next((i for i, (a, s) in enumerate(zip(array, sortedarray)) if a != s), -1)
        b = next((i for i, (a, s) in enumerate(zip(array[:: -1], sortedarray[:: -1])) if a != s), -1)
        return -1 in (a, b) and [-1, -1] or [a, len(array) - b - 1]
```

### 单调栈

左右单调栈，但没有快排快。

```python []
class Solution:
    def subSort(self, array: List[int]) -> List[int]:
        left, right, n = [], [], len(array)
        a, b = n, -1
        for i, l in enumerate(array):
            while left and l < array[left[-1]]:
                a = min(a, left.pop())
            left.append(i)
            j, r = n - 1 - i, array[n - 1 - i]
            while right and r > array[right[-1]]:
                b = max(b, right.pop())
            right.append(j)
        return a < b and [a, b] or [-1, -1]
```
