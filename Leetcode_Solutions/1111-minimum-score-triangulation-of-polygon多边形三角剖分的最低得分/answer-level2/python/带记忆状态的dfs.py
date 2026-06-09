### 解题思路
三角形：三点的乘积就是结果。
四边形：[a,b,c,d] = min((a*b*c + c*d*a), (b*c*d + d*a*b))
似乎只要把数组当环形来看待就可以解出来。
五边形。。。完全不适用。。。

提示里面给了个关键点：不论怎么分，A[0]和A[n-1]构成的边必然属于某个三角形。那么可以以这一边为基准，再配合1，2，3。。。n-2中任意一个点，可以获得一个三角形，和另外两个比之前多边形更小的n边形。这样一个复杂问题得以拆解。

为什么要用A[0]和A[n-1]构成的边为基准，因为这样拆出来的小多边形，顶点在数组上还是连续的，便于处理。

### 代码

```python
class Solution(object):
    def minScoreTriangulation(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        def recurse(array):
            if len(array) <= 2:
                return 0

            if array not in cache:
                if len(array) == 3:
                    result = array[0] * array[1] * array[2]
                else:
                    triangle = array[0] * array[-1]
                    result = float("inf")
                    for i in range(1, len(array) - 1):
                        result = min(result,
                                     triangle * array[i] + recurse(array[:i + 1]) + recurse(array[i:]))
                cache[array] = result

            return cache[array]

        cache = {}
        result = recurse(tuple(A))
        return result
```