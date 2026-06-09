### 解题思路
首先通过sorted（归并排序）将整个events进行排序；
然后安排各event并整合可参加会议到set中；
由于set在进行in操作时比list性能高很多，故弃用list选用set进行会议的存储。

### 代码

```python3
from typing import List


class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        if not events:
            return 0
        events = sorted(events,key=lambda x: x[1])
        plain = set()
        for event in events:
             for i in range(event[0], event[1]+1):
                if i not in plain:
                    plain.add(i)
                    break
        return len(plain)

```