### 解题思路
![2019-12-29 23-18-26屏幕截图.png](https://pic.leetcode-cn.com/889904c773e338a61296e1258c3bddc92473060608b6dec1fee46040c279d5f2-2019-12-29%2023-18-26%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)


### 代码

```python3
class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        res = sum([A[i] * i for i in range(len(A))])
        b = res
        sum_A = sum(A)
        for i in range(len(A)-1,-1,-1):
            b = b - A[i] * len(A) + sum_A
            res = max(b,res)
        return res
```