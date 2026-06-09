### 解题思路
BFS

### 代码

```python []
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        q, v, n = [start], {start}, len(arr)
        while q:
            p = []
            for i in q:
                if not arr[i]:
                    return True
                for j in i - arr[i], i + arr[i]:
                    if 0 <= j < n and j not in v:
                        p.append(j)
                        v.add(j)
            q = p
        return False
```

### 解题思路
记忆化DFS

### 代码

```python []
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n, v = len(arr), {}
        def f(i):
            if not arr[i]:
                v[i] = True
            elif i not in v:
                v[i] = False
                v[i] = 0 <= i - arr[i] < n and f(i - arr[i]) or 0 <= i + arr[i] < n and f(i + arr[i])
            return v[i]
        return f(start)
```
```python []
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n, v = len(arr), set()
        def f(i):
            if not arr[i]:
                return True
            elif i not in v:
                v.add(i)
                return 0 <= i - arr[i] < n and f(i - arr[i]) or 0 <= i + arr[i] < n and f(i + arr[i])
        return f(start)
```


![image.png](https://pic.leetcode-cn.com/7d6642e57d0cffc7dad1e60c0a74b82c968b1ee133ee489b8b4bd8e39c74685e-image.png)
