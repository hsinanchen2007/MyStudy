### 解题思路
病毒接触式传播扩展 上下左右

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def f(i,j,s,m,n,k):
            if 0<=i<m and 0<=j<n and (i,j) not in s:
                # sum_i = sum([int(val) for val in list(str(i))])
                # sum_j = sum([int(val) for val in list(str(j))])
                # if sum_i + sum_j <= k:
                if sum([int(val) for val in list(str(i)+str(j))]) <= k:
                    s.append((i,j))
        s = [(0,0)]
        for i,j in s:
            f(i+1,j,s,m,n,k)
            f(i-1,j,s,m,n,k)
            f(i,j+1,s,m,n,k)
            f(i,j-1,s,m,n,k)
        return len(s)
```