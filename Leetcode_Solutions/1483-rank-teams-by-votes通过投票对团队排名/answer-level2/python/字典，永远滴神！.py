建立字典干就完事

### 代码

```python3
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        if list(votes) == 1:
            return votes[0]
        rank = {}
        for i in votes[0]:
            rank[i] = [0]*len(votes[0])
        for i in votes:
            for j in range(len(i)):
                rank[i[j]][j] += 1
        rank = sorted(rank.items(),key = lambda x : (x[1],-ord(x[0])),reverse = True)
        result = ""
        for i in rank:
            result += i[0]
        return result
```