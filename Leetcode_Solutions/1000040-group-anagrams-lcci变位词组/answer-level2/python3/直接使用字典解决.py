```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        tmp = {}
        for i in strs:
            ori = "".join(sorted(i))
            if ori in tmp:
                tmp[ori].append(i)
            else:
                tmp[ori] = [i]
        return[tmp[i] for i in tmp]
```
