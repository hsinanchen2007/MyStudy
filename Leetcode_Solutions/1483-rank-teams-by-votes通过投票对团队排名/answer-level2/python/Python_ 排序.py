### 解题思路
创建一个hash table，key值是队伍名，用一个list来保存每个名次的次数。最后排序就可以了。

### 代码

```python
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        if not votes: return ''
        n_teams = len(votes[0])
        dic = {c: [0 for _ in range(n_teams)] for c in set(votes[0])}
        
        for vote in votes:
            for i, v in enumerate(vote):
                dic[v][i] +=1        
        
        return ''.join(sorted(dic.keys(), key = lambda x: ([-dic[x][i] for i in range(n_teams)], x)))
```