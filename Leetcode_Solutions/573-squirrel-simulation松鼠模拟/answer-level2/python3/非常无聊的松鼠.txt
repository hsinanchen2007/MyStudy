松鼠任选一个坚果作为第一个取的坚果，则
总移动距离=松鼠到该坚果的距离+树到该坚果的距离+其他坚果到树的距离*2
感觉还能优化吧。。。。
```python
from math import fabs
class Solution:
    def minDistance(self, height: int, width: int, tree: List[int], squirrel: List[int], nuts: List[List[int]]) -> int:
        nut_tree_res = [fabs(tree[0] - nut[0]) + fabs(tree[1] - nut[1]) for nut in nuts]
        squ_nut_res = [fabs(squirrel[0] - nut[0])  + fabs(squirrel[1] - nut[1]) for nut in nuts]
        min_res = 999999999
        for i in range(len(nuts)):
            tmp = nut_tree_res[:]
            tmp.pop(i)
            res = squ_nut_res[i] + nut_tree_res[i] + 2*sum(tmp)
            min_res = min(res, min_res)
        return int(min_res)
```