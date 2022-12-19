用了两个库函数
```
from math import gcd
from functools import reduce
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        res=reduce(lambda a,b:[b*a[0]+a[1],a[0]],cont[::-1],[1,0])
        return [i//gcd(*res) for i in res]
```
执行用时 : 36 ms , 在所有 Python3 提交中击败了 100.00% 的用户 内存消耗 : 13.6 MB , 在所有 Python3 提交中击败了 100.00% 的用户