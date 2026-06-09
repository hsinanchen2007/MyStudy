python3 一行代码，把出现字符次数为奇数的个数找出来即可
```python []
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        return len(s) >= k and sum(map(lambda x: x % 2, Counter(s).values())) <= k
```
