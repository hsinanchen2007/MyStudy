# 解题思路

1. 如果 `n <= 26`，直接返回字母表中对应的位置
2. 如果`n > 26`， 则`26除n`的结果作为结果的第一部分（递归获得）， 第二部分则是`26模n`，两部分拼接即为结果

# 代码

```python3
class Solution:
    def convertToTitle(self, n: int) -> str:
        table = [*map(chr, range(65, 91))]
        if n <= 26: return table[n - 1]
        return self.convertToTitle((n - 1) // 26) + table[(n - 1) % 26]
```