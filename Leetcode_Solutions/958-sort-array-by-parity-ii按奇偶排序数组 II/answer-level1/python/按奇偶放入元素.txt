### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        B = [0] * len(A)
        e, o = 0, 1
        for num in A:
            if num % 2 != 0:
                B[o] = num
                o += 2
            else:
                B[e] = num
                e += 2
        return B

```