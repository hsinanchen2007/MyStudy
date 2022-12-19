### 解题思路
1. 采用了“快排”中的partion 思想，10分钟内提交并通过，并非一次性提交通过，还是遇到了语法错误
2. 之后看官方题解，也是最优的解法。

### 代码

```python3
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        l = 0
        h = len(A) - 1
        if h < 1:
            return A 
        
        while l < h:
            while l < h and A[h] % 2 == 1:
                h -= 1
            while l < h and A[l] % 2 == 0:
                l += 1
            if l < h:
                A[h], A[l] = A[l], A[h]
        return A 
```