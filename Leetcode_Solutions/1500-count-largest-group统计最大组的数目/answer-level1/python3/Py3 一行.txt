一行
```python []
class Solution:
    def countLargestGroup(self, n: int) -> int:
        return max(Counter((Counter(map(lambda x: sum(map(int, str(x + 1))), range(n))).values())).items())[1]
```
