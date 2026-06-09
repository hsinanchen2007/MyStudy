新OJ不需要写functools和math啦，美滋滋
```python3 []
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        return reduce(gcd, nums) == 1
```



下面是老代码
2行更清楚一些，不过一行也可以
```python3 []
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        return __import__("functools").reduce(math.gcd, nums) == 1
```
