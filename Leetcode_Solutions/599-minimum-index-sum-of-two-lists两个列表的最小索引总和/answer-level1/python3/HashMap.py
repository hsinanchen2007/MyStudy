### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        dict = {}
        res = []
        minmum = len(list1) + len(list2)
        for i, l in enumerate(list1):
            dict[l] = [i]
        for j, m in enumerate(list2):
            if list2[j] in dict:
                dict[m].append(j) 
        for k, value in dict.items():
            if len(value) == 2 and sum(value) <= minmum:
                minmum = sum(value)
                res.append(k)
        return res

            
```