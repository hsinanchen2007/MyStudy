### 解题思路
首先需要将字符转换为ASCII码，然后按列比较

### 代码

```python
class Solution(object):
    def minDeletionSize(self, A):
        if len(A) == 1:
            return 0
        temp = []
        ans = 0
        for i in range(len(A)):
            for c in A[i]:
                temp += [ord(c)]
            A[i] = temp
            temp = []
        for i in range(len(A[0])):
            for j in range(1,len(A)):
                if A[j][i] < A[j-1][i]:
                    ans += 1
                    break
        return ans
```