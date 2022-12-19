我有点好奇这题为什么会出在这本书里...有看过的朋友解释一下吗
```python
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        a = sorted(numbers)
        return a[0]
```

```python
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        for i in range(1, len(numbers)):
            if numbers[i] < numbers[i-1]:
                return numbers[i]
        return numbers[0]
```