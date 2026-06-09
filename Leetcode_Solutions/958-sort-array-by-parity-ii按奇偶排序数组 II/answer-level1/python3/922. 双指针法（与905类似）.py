### 解题思路
与905类似，不同的是，905中的双指针是左右两个向中间移动。
而这道题中双指针的设计是用来记录奇偶位的，这样直接判断奇数位是否为奇数，偶数位是否为偶数即可。

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        odd = 1
        even = 0

        while odd < len(A) and even < len(A):
            if A[odd] % 2 == 0 and A[even] % 2 == 1:
                A[odd], A[even] = A[even], A[odd]
                even += 2
                odd += 2
            elif A[odd] % 2 == 1:
                odd += 2
            elif A[odd] % 2 == 0:
                even += 2
        
        return A
```