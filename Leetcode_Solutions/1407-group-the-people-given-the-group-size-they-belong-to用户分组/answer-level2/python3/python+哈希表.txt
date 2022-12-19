### 解题思路
哈希表遍历一遍，多的再细分一下

### 代码

```python3
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        d = {}
        for i in range(len(groupSizes)):
            if groupSizes[i] in d:
                d[groupSizes[i]].append(i)
            else:
                d[groupSizes[i]] = []
                d[groupSizes[i]].append(i)
        ans = []
        for item in d.keys():
            if len(d[item]) == item:
                ans.append(d[item])
            else:
                for i in range(0,len(d[item]),item):
                    ans.append(d[item][i:i+item])
        return ans
```