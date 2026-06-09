### 解题思路
暴力遍历所有数字，记录次数，找到公约数

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        number_count = collections.Counter(deck)
        N = len (deck)
        for X in range(2, N+1):
            if N % X == 0 :
                if all(v % X == 0 for v in number_count.values()):
                    return True
        return False
```