### 解题思路
看了很多人好像写着很复杂，其实一行搞定
1、双循环遍历所有结果
2、满足要求则返回x,y的值

### 代码

```python3
"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:

        return [[x,y] for x in range(1,z+1) for y in range(1,z+1) if customfunction.f(x, y) == z]
```