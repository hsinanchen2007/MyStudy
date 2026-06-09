### 解题思路
广度遍历

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        que = []
        ss = [[0 for _ in range(n)] for _ in range(m)]
        que.append((0,0))
        count = 0
        while que:
            x, y = que.pop(0)
            if ss[x][y] == 1:
                continue
            else:
                ss[x][y] = 1
                count+=1
            if x+1 < m and self.getsum(x+1, y) <= k:
                que.append((x+1, y))
            if x-1 >=0 and self.getsum(x-1, y) <= k:
                que.append((x-1, y))
            if y+1 < n and self.getsum(x, y+1) <= k:
                que.append((x, y+1))
            if y-1 >= 0 and self.getsum(x, y-1) <= k:
                que.append((x, y-1))
        return count

    def getsum(self, xx, yy):
        s = []
        while xx:
            s.append(xx%10)
            xx = xx // 10
        while yy:
            s.append(yy%10)
            yy = yy // 10
        return sum(s)
```