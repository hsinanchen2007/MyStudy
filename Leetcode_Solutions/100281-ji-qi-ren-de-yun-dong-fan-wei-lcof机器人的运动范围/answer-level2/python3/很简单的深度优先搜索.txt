### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:

        visited=set()
        def calsum(i,j):
            i=list(map(int,list(str(i))))
            j=list(map(int,list(str(j))))

            return sum(i)+sum(j)

        def dsf(i,j):
            if i>=0 and j>=0 and i<m and j<n and calsum(i,j)<=k and (i,j) not in visited:
                visited.add((i,j))
            else:
                return
            dsf(i+1,j)
            dsf(i-1,j)
            dsf(i,j-1)
            dsf(i,j+1)

        dsf(0,0)
        return len(visited)

```