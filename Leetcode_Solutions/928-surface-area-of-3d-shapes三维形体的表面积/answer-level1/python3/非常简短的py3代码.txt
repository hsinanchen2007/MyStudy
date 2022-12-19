### 解题思路
很容易理解，派n个小人，横向走一遍，纵向走一遍，小人上下台阶都费力，把费力值求和，加上数组中>0的个数*2就是答案
每个小人从平地开始，到平地。在走台阶的时候，只需要记录上一次的台阶和本次台阶的差值绝对值，就是费力值。
横向走一遍，纵向走一遍，即只需要再次调用函数，传入numpy的转置即可

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        import numpy
        N=len(grid)
        def S(L):
            Sum=0
            for i in L:
                Last=0
                for j in i:
                    Sum+=abs(j-Last)
                    Last=j
                Sum+=Last
            return Sum
        return S(numpy.array(grid).T)+S(grid)+numpy.sign(grid).sum()*2
```