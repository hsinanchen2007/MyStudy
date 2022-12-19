Python3双百，用hashtable解决，主要的时间消耗是对子串进行排序判断
```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        position = dict()
        result = list()
        counter = 0

        for term in strs:
            sorted_term = "".join(sorted(term))
            if sorted_term not in position.keys():
                result.append([term])
                position[sorted_term] = counter
                counter += 1
            else:
                result[position[sorted_term]].append(term)

        return result
```
