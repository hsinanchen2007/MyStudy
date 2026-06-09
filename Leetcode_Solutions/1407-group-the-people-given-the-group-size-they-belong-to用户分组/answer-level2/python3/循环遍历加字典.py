### 解题思路
循环遍历一遍，字典来记住出现的次数

### 代码

```python3
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        res = []
        my_dict = {}
        for i in range(len(groupSizes)):
            if my_dict.get(groupSizes[i]) == None:
                my_dict[groupSizes[i]] = [i]
                if len(my_dict[groupSizes[i]]) == groupSizes[i]:
                    res.append(my_dict[groupSizes[i]])
                    my_dict.pop(groupSizes[i])
            else:
                my_dict[groupSizes[i]].append(i)
                if len(my_dict[groupSizes[i]]) == groupSizes[i]:
                    res.append(my_dict[groupSizes[i]])
                    my_dict.pop(groupSizes[i])
        return res



```