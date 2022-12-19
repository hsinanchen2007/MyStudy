### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def dis(x, y):
            res = 0
            while x:
                res += x%10
                x //= 10
            while y:
                res += y%10
                y //= 10
            return res   
        if k == 0: return 1
        flag = [[False]*n for _ in range(m)]
        flag[0][0] = True
        queue = [(0,0)]
        ans = 1
        while(len(queue) > 0):
            x, y = queue.pop(0)
            for dx, dy in [(0,1),(1,0)]:
                tx = x+dx
                ty = y+dy
                if tx<m and ty<n and not flag[tx][ty] and dis(tx,ty)<=k:
                    flag[tx][ty] = True
                    queue.append((tx,ty))
                    ans =ans+1
        return ans
```