### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A):
        A = sorted(A)
        p = [0]*40005
        ans = 0
        tmp = 0
        for i in range(len(A)):
            p[A[i]] += 1
        for i in range(len(p)):
            ans += tmp
            if p[i]>1:tmp += p[i]-1
            elif p[i]==0 and tmp>0:tmp -= 1
        ans += (tmp+1)*tmp/2
        return int(ans)
            
```