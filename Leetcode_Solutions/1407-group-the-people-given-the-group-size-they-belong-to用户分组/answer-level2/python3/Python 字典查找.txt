```python
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        dic = {}
        res = []
        for index, group in enumerate(groupSizes):
            try:
                dic[group].append(index)
            except:
                dic[group] = [index]

            if len(dic[group]) == group: # 如果这个组满了就把这个组添加到答案中
                res.append(dic[group])
                del dic[group]
        return res
```
