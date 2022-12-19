### 解题思路

可以看成有向图上求最长路径。

把这个数组转换成一个无环有向图。

利用 mp 数组存每个点能直接到达的节点。

dfs 用于递归求一个点的解。一个点的解就是这个点能到的所有点里解最大的一个加一。（如果他哪也到不了，就是 1）

ansx 做了记忆化搜索，防止求重复的点的解。这里可以使用 functools 中的 lru_cache(None) 代替自己定义数组，写法更简洁。

### 代码
不用 functools：
```python
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        l = len(arr)
        mp = [[] for i in range(l)]
        for i in range(l):
            j = i - 1
            while j >= 0:
                if i - j > d: break
                if arr[j] >= arr[i]: break
                mp[i].append(j)
                j -= 1
            j = i + 1
            while j < l:
                if j - i > d: break
                if arr[j] >= arr[i]: break
                mp[i].append(j)
                j += 1
        ansx = [0] * l
        def dfs(i):
            if ansx[i] != 0: return ansx[i]
            if len(mp[i]) == 0:
                ansx[i] = 1
                return 1
            ans = dfs(mp[i][0])
            for toid in mp[i][1:]:
                ans = max(ans, dfs(toid))
            ansx[i] = ans + 1
            return ans + 1
        ans = dfs(0)
        for i in range(1, l):
            ans = max(ans, dfs(i))
        return ans
```

使用 functools.lru_cache

```python
import functools
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        l = len(arr)
        mp = [[] for i in range(l)]
        for i in range(l):
            j = i - 1
            while j >= 0:
                if i - j > d: break
                if arr[j] >= arr[i]: break
                mp[i].append(j)
                j -= 1
            j = i + 1
            while j < l:
                if j - i > d: break
                if arr[j] >= arr[i]: break
                mp[i].append(j)
                j += 1
        @functools.lru_cache(None)
        def dfs(i):
            if len(mp[i]) == 0:
                return 1
            ans = dfs(mp[i][0])
            for toid in mp[i][1:]:
                ans = max(ans, dfs(toid))
            return ans + 1
        ans = dfs(0)
        for i in range(1, l):
            ans = max(ans, dfs(i))
        return ans
```