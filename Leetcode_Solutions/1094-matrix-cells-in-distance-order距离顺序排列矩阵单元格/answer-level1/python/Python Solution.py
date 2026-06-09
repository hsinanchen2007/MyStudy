### 解题思路
1. build a list of matrix 
2. return the list sorted by Manhattan Distance
### 代码

```python
class Solution(object):
    def allCellsDistOrder(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        dist = [[i,j] for i in range(R) for j in range(C)]
        dist.sort(key=lambda x: abs(x[0]-r0)+abs(x[1]-c0))
        return dist


```