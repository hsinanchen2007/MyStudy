### 解题思路
首先将个元素余数的频次记录到字典中，两余数之和为60的元素对可行，当余数为30，余数为0时，元素对在内部产生。
### 代码

```python
class Solution(object):
    def numPairsDivisibleBy60(self, time):
        if len(time) < 2:
            return 0
        dic = {}
        count = 0
        for c in time:
            mod_c = c % 60
            if mod_c not in dic:
                dic[mod_c] = 1
            else:
                dic[mod_c] += 1
        for c in dic:
            if c == 0 or c == 30:
                count += 1.0*dic[c]*(dic[c]-1)/2
            else:
                if 60 - c in dic: 
                    count += 1.0*dic[c]*dic[60-c]/2
        return int(count)
```