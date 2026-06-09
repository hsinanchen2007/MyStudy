本题与搜索二维矩阵习题解法一致 [面试题04. 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

对于搜索带有偏序的二维矩阵，可以采用双指针法，(i,j) 从右上角开始搜索，如果偏大，就往左边走；如果偏小，就往右边走。

对于面试题 04, 我最初是采用了分治递归法，写法麻烦，但效率较高。

还有类似的一题 [1351. 统计有序矩阵中的负数](https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/)




```python3
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        a, b = 1, 1000
        result = []
        while (a<=1000) and (b>=1):
            if customfunction.f(a, b) == z:
                result.append([a, b])
                a += 1
                b -= 1
            elif customfunction.f(a, b) > z:
                b -= 1
            else:
                a += 1
        return result
```