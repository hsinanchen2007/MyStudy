### 解题思路
双指针解决奇偶排序问题

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        odd, even = 1, 0
        while odd < len(A) and even < len(A):
            while even < len(A) and A[even] % 2 == 0:
                even += 2
            while odd < len(A) and A[odd] % 2 == 1:
                odd += 2
            if even >= len(A) and odd >= len(A):
                return A
            A[even], A[odd] = A[odd], A[even]
```