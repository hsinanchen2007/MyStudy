* 与[55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game)和[45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii)不同的是，该题的跳跃是双向的，所以不便于使用动态规划。我们采用的方法是dfs，把未被访问过（通过建立`visited`数组来记录）的两边跳跃的索引入栈。基于的前提是：如果第二次访问某点，说明它被访问过了；如果它被访问过而我们还没结束程序，说明通过它到达不了目的点；既然它不行，我们这次都不必睬它了，何必入栈呢。

```python []
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        m = len(arr)
        visited = [False] * m
        stack = [start]
        while stack:
            curr = stack.pop()
            # print(curr, arr[curr])
            visited[curr] = True
            if arr[curr] == 0:
                return True
            step = arr[curr]
            if curr - step >= 0 and not visited[curr - step]:
                stack.append(curr - step)
            if curr + step <= m-1 and not visited[curr + step]:
                stack.append(curr + step)
        return False
```