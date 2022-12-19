```
def groupAnagrams(strs):
    """
    :type strs: List[str]
    :rtype: List[List[str]]
    """
    dicts={}
    for i in strs:
        if tuple(sorted(i)) not in dicts:
            dicts[tuple(sorted(i))]=[i]
        else:
            dicts[tuple(sorted(i))].append(i)
    return dicts.values()
```
