### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        if B in A:
            return 1
        if len(set(A).union(set(B))-set(A))>0:
            return -1
        index=[]
        for i in range(len(A)):
            if B[0]==A[i]:
                index.append(i)
        repeat=1
        As=A*repeat
        while len(As)-index[-1]<len(B):
            if len(As)-index[0]>=len(B):
                if B in As:
                    return repeat
            repeat+=1
            As=A*repeat
        if B in As:
            return repeat
        return -1
```