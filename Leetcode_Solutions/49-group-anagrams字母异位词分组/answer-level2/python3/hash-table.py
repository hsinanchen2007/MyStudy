```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if not strs:
            return []
        d= {}
        for i in strs:
           if d.get(''.join(sorted(list(i)))):
               d[''.join(sorted(list(i)))].append(i)
           else:
               d[''.join(sorted(list(i)))] = [i]
        return [i for i in d.values()]
```