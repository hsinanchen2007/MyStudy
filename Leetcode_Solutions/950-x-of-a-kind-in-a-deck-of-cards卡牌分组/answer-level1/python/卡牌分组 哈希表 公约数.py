### 解题思路
利用字典找到每一元素的个数，找到最小频次min_x,若min_x < 2,则False；当min_x >= 2时，需要考虑这些重复数字的频次是否具有公约数，若存在，则返回True

### 代码

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        dic = {}
        for c in deck:
            if c not in dic:
                dic[c] = 1
            else:
                dic[c] += 1
        values = list(dic.values())
        min_x = min(values)
        if min_x >= 2:
            for i in range(2,min_x+1):
                if min_x % i == 0 and all(c % i == 0 for c in values):
                    return True
        return False
```