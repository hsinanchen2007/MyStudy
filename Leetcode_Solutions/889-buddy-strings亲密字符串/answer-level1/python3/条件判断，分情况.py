

### 代码

```python3
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        i = 0
        c = 0
        a = 0
        b = 0
        if A == B and len(A) != len(set(A)):
            return True
        elif A == B:
            return False
        tmp = []
        while i < len(A):
            if A[i] != B[i]:
                tmp.append(i)
                c += 1
            if c > 2:
                return False
            i += 1
        A = [i for i in A]
        A[tmp[0]], A[tmp[1]] = A[tmp[1]], A[tmp[0]]
        A = "".join(A)
        return A == B

```