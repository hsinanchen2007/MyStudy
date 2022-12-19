### 解题思路
用字典将数据分组，求values是否存在大于1的公约数

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        
        group = {}
        for i in deck:
            if i in group:
                group[i] += 1
            else:
                group[i] = 1

        for i in range(2,min(group.values())+1):
            count = 0
            for num in group.values():
                if num % i != 0:
                    break
                count += 1
            if count == len(group):
                return(True)
        
        return(False)
        
```