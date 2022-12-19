### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        S = sum(A)
        if S % 3:
            return False
        s = 0
        S /= 3
        for i in range(1,len(A)-1):
            s += A[i-1]
            if s == S:
                l = A[i]
                for j in range(i+1,len(A)):
                    if l == S:
                        return True
                    else:
                        l += A[j]
            
        return False
```