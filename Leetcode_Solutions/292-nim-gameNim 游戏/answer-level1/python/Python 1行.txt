```python
class Solution:
    def canWinNim(self, n: int) -> bool:
        return bool(n % 4)
```
- 只要轮到你的时候剩余石头数量不是 4 的倍数都是完胜，因为你有办法使得每次轮到对方的时候剩余石头数量都为 4 的倍数

