### 解题思路
![image.png](https://pic.leetcode-cn.com/c674669c75ba7160d3ae807d12c2796364145491c1cc099305448314f25ada45-image.png)

- 转换为图的层次遍历即可

### 代码

```python
from collections import defaultdict, deque


class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        graph = defaultdict(set)

        for p, pp in zip(pid, ppid):
            graph[pp].add(p)

        ans = []
        d = deque()
        d.append(kill)
        while d:
            cur = d.popleft()
            ans.append(cur)
            d.extend(graph[cur])

        return ans
```