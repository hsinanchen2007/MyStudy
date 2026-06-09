### 解题思路
先按序号由小到大分组，如果超过了小组的最大容量，重新建一组。
消除掉其中人数为0的组。


### 代码

```python3
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        res = []
        for i in range(1, max(groupSizes)+1):
            res.append([])
            for j in range(len(groupSizes)):
                if groupSizes[j] == i:
                    if len(res[-1]) < i:
                        res[-1].append(j)
                    else:
                        res.append([j])
        res1 = []
        for l in res:
            if l != []:
                res1.append(l)
        return res1
```