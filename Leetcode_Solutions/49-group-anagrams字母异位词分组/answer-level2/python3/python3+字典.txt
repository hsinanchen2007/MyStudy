```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strs1 = strs[:]
        for i in range(len(strs)):
            strs[i] = sorted(strs[i])
        d = {}
        for i in range(len(strs)):
            if tuple(strs[i]) in d:
                d[tuple(strs[i])].append(strs1[i])
            else:
                d[tuple(strs[i])] = []
                d[tuple(strs[i])].append(strs1[i])
        return list(d.values())
```
