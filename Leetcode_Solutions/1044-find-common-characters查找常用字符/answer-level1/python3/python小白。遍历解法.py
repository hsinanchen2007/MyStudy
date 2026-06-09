### 解题思路
遍历暴力法
### 代码

```python3
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        A = list(map(list,sorted(A,key = lambda x :len(x))))
        i = 0
        result = []
        while i <= len(A[0])-1:
            k = 0
            while k <= len(A)-1:
                if A[0][i] in A[k]:
                    k += 1
                else:
                    break
            if k == len(A):
                result.append(A[0][i])
                de = A[0][i]
                for j in range(1,len(A)):
                    A[j].remove(de)
            i += 1
        return result
```