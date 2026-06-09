```
class Solution:
    def addToArrayForm(self, A, K):
        for i in range(len(A)):
            A[i] = str(A[i])
        num = str(int("".join(A))+int(K))
        ans = []
        for i in range(len(num)):
            ans.append(int(num[i]))
        return ans
```
