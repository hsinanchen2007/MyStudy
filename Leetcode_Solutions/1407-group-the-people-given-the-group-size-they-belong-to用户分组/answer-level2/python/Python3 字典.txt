* 遍历输入列表，用value做key，{value:[index1,index2...]}
* 如果超过value长度，就拿出来放在 res 里
```python
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        temp = {}
        res = []
        if len(groupSizes) == 0:
            return []
        for index,value in enumerate(groupSizes):
            if value in temp:
                if len(temp[value]) < value:
                    temp[value].append(index)
                else:
                    res.append(temp[value])
                    temp[value] = [index]
            else:
                temp[value] = [index]
        res.extend([v for v in temp.values()])
        return res
```
