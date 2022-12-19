### 1. 直接法
直接暴力判断，代码如下：
```
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        count = 0
        for i in S:
            if i in J:
                count +=1 
        return count
```
时间复杂度：O(m*n), 空间复杂度：O(l)