```python
class Solution:
    def groupAnagrams(self, strs):
        return [[*x] for _, x in itertools.groupby(sorted(strs, key=sorted), sorted)]
```
- 使用 groupby 函数依据 sorted 结果分组
```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = collections.defaultdict(list)
        for s in strs:
            d[''.join(sorted(s))].append(s)
        return [*d.values()]
```
- 以排序后的单词为 key，将所有字符串分组存入预定义字典