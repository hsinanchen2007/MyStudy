### 解题思路
要计算从CEO到小兵的最大加权长度，自然想到DFS。首先用hash table建立一个有向graph，key为manager，value为包含手下所有direct reports的list。从CEO开始往下dfs，同时记录通知到此员工的时间。如果此员工没有手下，说明已经通知到小兵了，则与所需时间比较取大。最后输出所需时间即可。

### 代码

```python
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        dic = {mng: [] for mng in set(manager) if mng != -1}
        for i, v in enumerate(manager):
            if v != -1:
                dic[v].append(i)
        s = [(headID,0)]
        time_needed = 0
        while s:
            mng, time = s.pop()
            if mng in dic:
                for p in dic[mng]:
                    s.append((p, time + informTime[mng]))
            else:
                time_needed = max(time_needed, time)
        return time_needed
```