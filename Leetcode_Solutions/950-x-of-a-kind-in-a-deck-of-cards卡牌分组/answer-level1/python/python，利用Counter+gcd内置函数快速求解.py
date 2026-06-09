### 解题思路
- 先用collections.counter类统计各数字个数
- 然后以频度最小的为基准，辗转相除法求解所有数字个数的最大公约数
- 当最大公约数>1时返回True，否则返回False
- 进一步地，可以利用reduce归约函数实现辗转相除

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        import functools
        return functools.reduce(math.gcd, collections.Counter(deck).values()) > 1
```