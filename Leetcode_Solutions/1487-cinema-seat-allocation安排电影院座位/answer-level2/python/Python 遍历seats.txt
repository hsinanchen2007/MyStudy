影响每一排结果的只有4块位置
```
l     ml    mr    r
2 3 | 4 5   6 7 | 8 9
```
遍历`seats`统计一下收到影响的行数.
没有被影响的行, 直接安排2个家庭就可以
受到影响的判断一下改行应该安排几个家庭


```python
from typing import List
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        res = 0
        left = [2, 3]
        right = [8, 9]
        midr = [6, 7]
        midl = [4, 5]
        d = {}
        ### [0, 1, 2, 3] l ml mr r
        len_d = 0
        for i, idx in reservedSeats:
            if i not in d:
                len_d += 1
                d[i] = [1, 1, 1, 1]
            if idx in right:
                d[i][3] = 0
            elif idx in left:
                d[i][0] = 0
            elif idx in midl:
                d[i][1] = 0
            elif idx in midr:
                d[i][2] = 0
        res = 2 * (n - len_d)
        for k, (l, ml, mr, r) in d.items():
            # ml & l 左边 mr & r 右边
            res += (ml & l) + (mr & r)
            if l == 0 and r == 0:
                # 对 0 1 1 0 特判, 中间放一个家庭
                res += (ml & mr)
        return res
```