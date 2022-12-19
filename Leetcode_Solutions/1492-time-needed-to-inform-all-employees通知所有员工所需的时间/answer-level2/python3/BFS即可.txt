### 解题思路
遍历时记录每个节点接到消息经过的时间，最后比较最大即可。
将manager中记录的树关系用字典整理记录，每一项为（上级：[下级们], 用时），更方便使用。

### 代码

```python3
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        relation = dict().fromkeys(range(n))
        for key in relation.keys():
            relation[key] = [[], 0]
        for i in range(n):
            if i!= headID:
                relation[manager[i]][0].append(i)
        queue = [headID]
        while queue:
            Next = []
            for mana in queue:
                for stuff in relation[mana][0]:
                    relation[stuff][1] += relation[mana][1] + informTime[mana]
                Next.extend(relation[mana][0])
            queue = Next
        return max([val[1] for val in relation.values()])
```