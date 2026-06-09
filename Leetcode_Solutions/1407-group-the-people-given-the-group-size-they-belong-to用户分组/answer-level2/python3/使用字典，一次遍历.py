```
class Solution:
    def groupThePeople(self, groupSizes):
        group = {}
        for i, n in enumerate(groupSizes):
            if not group.get(n):
                group[n] = [[i]]
            elif len(group[n][-1]) < n:
                group[n][-1].append(i)
            else:
                group[n].append([i])
        return [i for g in group.values() for i in g]
```
