### 解题思路
奇指针和偶指针，找到不满足条件的调换，当任意一个指针到末尾，返回

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        odd=1

        for even in range(0,len(A),2):
            if A[even]%2:
                while A[odd]%2:
                    odd+=2
                A[even],A[odd]=A[odd],A[even]
        return A
```