![image.png](https://pic.leetcode-cn.com/c0e84de6e6483ab6faff64dfb8b7834bcf83094ea6f88994b2f99e0be6efbed6-image.png)


```
'''
(i, arr1[i], arr2[i])  和 (j, arr1[j], arr2[j])
可以看成三维平面上两个点，题目就是求两个点曼哈顿距离最大值


|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

把绝对值符号拆开

(x1 * arr1[i] + x2 * arr2[i] + x3 * i) - (x1 * arr1[j] + x2 * arr2[j] + x3 * j)
x1 x2 x3 一定是-1 或者1 所以对于一组x1 x2 x3而言，一定存在一个i 使得x1 * arr1[i] + x2 * arr2[i] + x3 * i
最大或者最小，把最大和最小的值都求出来，差值就是特定一组x1 x2 x3的表达式最大值，枚举8种最大值，
返回其中最大的一个


'''
from typing import List
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        ans = -0x7fffffff
        for x in [[1,1,1], [-1,1,1], [1,-1,1], [1,1,-1], [-1,-1,1], [-1,1,-1], [1,-1,-1], [-1,-1,-1]]:
            min_val, max_val = 0x7fffffff, -0x7fffffff
            for i in range(len(arr1)):
                val = x[0] * i + x[1] * arr1[i] + x[2] * arr2[i]
                min_val = min(min_val, val)
                max_val = max(max_val, val)
            ans = max(ans, (max_val - min_val))

        return ans
```
