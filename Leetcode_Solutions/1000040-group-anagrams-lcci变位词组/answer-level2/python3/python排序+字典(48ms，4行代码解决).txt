```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map_dic = {}
        for s in strs:
            map_dic.setdefault(tuple(sorted(s)), []).append(s)
        return list(map_dic.values())
```

