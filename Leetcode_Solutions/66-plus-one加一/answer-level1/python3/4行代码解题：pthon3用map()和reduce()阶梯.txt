采用map()函数和reduce()组合
优点：代码量少
缺点：用时太长

```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        from functools import reduce
        def f(x,y):
            return x * 10 + y
        return [int(x) for x in str(reduce(f,digits) +1)]

```
