![image.png](https://pic.leetcode-cn.com/556ce20d7ce50c0f60b7fc0c0e7248c426b0339e6de9dc69ec5ae2ed77acbd49-image.png)


```
'''
每个队统计得分组成的向量， 按照向量排序后输出队伍名称即可
'''

from typing import List
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        team_num = len(votes[0])
        m = {ch : [0 for _ in range(team_num)] for ch in votes[0]}

        for v in votes:
            for i, ch in enumerate(v):
                m[ch][i] -= 1

        l = sorted([tuple(v + [k]) for k, v in m.items()])
        return ''.join([v[-1] for v in l])
```
