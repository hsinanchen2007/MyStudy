### 解题思路
无...

### 代码

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        def backtrack(path,begin):
            if len(path) == k:
                result.append(path[:])
                return
            for i in range(begin,n+1):
                if i not in path:
                    path.append(i)
                    begin += 1
                    backtrack(path,begin)
                    path.pop()
        backtrack([],1)
        return result

```