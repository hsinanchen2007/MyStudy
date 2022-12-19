```python
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        count, res = {}, 0
        for a, b in dominoes:
            a, b = sorted([a, b])  # 始终按（小，大）作为键值
            count[a, b] = count.get((a, b), 0) + 1  # 计数
        for i in count.values():
            res += i * (i - 1)
        return res >> 1  # 最后再除以2

```
