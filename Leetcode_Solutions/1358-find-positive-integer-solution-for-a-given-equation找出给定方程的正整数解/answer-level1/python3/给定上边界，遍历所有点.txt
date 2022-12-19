### 解题思路
1. 给定函数的两个输入的上界，因为是单调递增函数，上界设为z即可
2. 遍历 (1,1)~(z+1,z+1) 之内所有的点(横纵坐标分别按1递增)。

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
        all_list = []

        for i in range(1,z+1):
            for j in range(1,z+1):
                if customfunction.f(i,j) == z:
                    all_list.append([i,j])
        
        return all_list
```