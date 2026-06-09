```python
import collections
def groupAnagrams(strs):
    dic = collections.defaultdict(list)
    for s in strs:
        _s = ''.join(sorted(s))
        dic[_s].append(s)

    return dic.values()

print(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
```