### 解题思路
写的很挫，轻喷。

### 代码

```python3
class Solution:
    def maxDistance(self, g):
        return -1 if all([len(set(i))==1 for i in g]) and len(set([i[0] for i in g]))==1 else(lambda b:((lambda d:[b.append((-1,j+1)) if i<0 else(d(i-1,j),d(i,j-1),d(i+1,j),d(i,j+1))for i,j in b if b[-1][0]+b[-2][0]!=-2])(lambda i,j:(b.append((i,j)),g[i].__setitem__(j, 1))if 0<=i<len(g) and 0<=j<len(g[0]) and g[i][j]==0 else 0),b[-2][1])[1])([(i,j) for i in range(len(g)) for j in range(len(g[0])) if g[i][j]==1]+[(-1,0)])
```