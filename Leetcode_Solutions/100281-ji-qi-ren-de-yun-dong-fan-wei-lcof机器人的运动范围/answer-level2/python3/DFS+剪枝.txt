### 解题思路
一开始的时候我直接递归访问上下左右四个方向，后来看题解发现只要遍历右下两个方向就可以了
速度提升了约50%
只能说各位提供题解的大佬太强了
### 代码

```python
class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        visited = [[0 for _ in range(n)] for _ in range(m)]
        def helper(num):
            tmp = [0]
            while num:
                tmp.append(num % 10)
                num = num // 10
            return tmp

        def dfs(x, y):
            if x < 0 or y < 0 or x >= m or y >= n or visited[x][y]: return 0
            if sum(helper(x)) + sum(helper(y)) <= k:
                visited[x][y] = 1
                return 1+dfs(x, y + 1)+dfs(x + 1, y)
            else:
                return 0

        return dfs(0, 0)
```