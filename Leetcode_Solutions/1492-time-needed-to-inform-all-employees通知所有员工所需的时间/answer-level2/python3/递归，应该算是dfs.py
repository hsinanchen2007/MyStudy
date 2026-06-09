### 解题思路
dfs，简单递归。

### 代码

```python3
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:

        manager_map = {}

        for i, v in enumerate(manager):
            if v not in manager_map.keys():
                manager_map[v] = []
            manager_map[v].append(i)

        # print(manager_map)
        def tmp_recursion(head, man_map, inform_time):
            re = 0
            if head not in man_map.keys():
                return 0
            else:
                for v in man_map[head]:
                    re = max(re, inform_time[v] + tmp_recursion(v, man_map, inform_time))
                return re


        return tmp_recursion(-1, manager_map, informTime)
```