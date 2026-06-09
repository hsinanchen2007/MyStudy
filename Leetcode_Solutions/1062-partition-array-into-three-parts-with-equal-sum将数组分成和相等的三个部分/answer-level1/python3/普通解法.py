### 解题思路
sum/3然后扫描一遍
### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s3 = sum(A)/3
        part = 0
        k = 0
        for i in range(3):
            s = s3
            for j in range(k,len(A)):
                s -= A[j]
                if s == 0:
                    break
            if not s == 0:
                return False
            if k >= len(A):
                break
            k = j + 1
            part += 1
        if  (part < 3):
            return False
        return True
        
```