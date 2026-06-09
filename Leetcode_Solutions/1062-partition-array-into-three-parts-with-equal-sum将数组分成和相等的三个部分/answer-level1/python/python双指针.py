思路：

第一眼，双指针

利用sum//3来判断，注意每次分割前后中间不能是空数组。

```python
class Solution:
    def canThreePartsEqualSum(self, A: [int]) -> bool:
        asum = sum(A)
        if asum % 3 > 0: return False
        part = asum // 3
        n = len(A)
        L, R = 0, n - 1
        pl, pr = A[0], A[n - 1]
        while L < R - 1:
            if pr == part and pl == part:
                return True
            if pl != part:
                L += 1
                pl += A[L]
            if pr != part:
                R -= 1
                pr += A[R]
        return False
```

> 执行用时 :60 ms, 在所有 Python3 提交中击败了98.63% 的用户
>
> 内存消耗 :18.4 MB, 在所有 Python3 提交中击败了98.29%的用户

就舒服就完了