刷探索刷到的, 判断排序后的字典和原字典是否相同就可以
```python
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        return words == sorted(words, key=lambda x: list(map(order.index, x)))
```