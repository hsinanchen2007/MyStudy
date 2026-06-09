### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if sum(A)%3 != 0:
            return False
        average = sum(A)//3
        n = 0
        count = 0
        for i in range(len(A)):
            n += A[i]
            if average == n:
                n = 0
                count += 1
                if count == 2 and i < len(A)-1:
                    return True
        return False
```
