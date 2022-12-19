## 解法：min(偶数位置个数，奇数位置个数)
---
### <如何理解>：
    偶数位置移动到偶数位置代价为0，奇数移到奇数位置代价为0，那么就只剩奇偶位置之间移动，哪个少即为答案
---
### <代码>  
```
class Solution:
    def minCostToMoveChips(self, chips) :

        odds = sum(i & 1 for i in chips)

        return min(odds, len(chips) - odds)

```