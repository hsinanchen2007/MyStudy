### 解题思路

很简单，直接看代码

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def fun(x):
            sum=0
            while(x):
                sum+=x%10
                x=x//10
            return sum
        visited = [[0] * n for _ in range(m)]

        # return the cnt from this point
        def helper(x, y):
            # print(x,y)
            if 0 <= x <m and 0 <= y < n and visited[x][y] == 0 and fun(x)+fun(y)<=k:
                visited[x][y] = 1
                return 1 + helper(x - 1, y) + helper(x + 1, y) + helper(x, y - 1) + helper(x, y + 1)
            else:
                return 0

        cnt = helper(0, 0)

        return cnt
```