抓住不变的相同的东西，异位词，排序后的字符串都是相同的，拿它当作key:

```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import defaultdict
        strs_dict = defaultdict(list)
        res = []
        for str in strs:
            key = ''.join(sorted(list(str)))
            strs_dict[key] += str.split(',')
        for k,v in strs_dict.items():
            res.append(v)
        return res
```
