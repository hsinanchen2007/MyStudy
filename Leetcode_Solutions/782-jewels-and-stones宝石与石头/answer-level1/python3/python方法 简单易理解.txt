对J中的每一项搜索S中出现的次数，再把已经搜索过的元素删去。


```
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        sum = 0
        for i in J:
            sum = sum + S.count(i)
            J.replace(i,"")
        return sum
```
