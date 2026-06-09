### 解题思路
才开始刷leetcode的小白，大家多多包涵
利用最大公约数解决问题（python中可调用gcd函数求）。
1)	根据条件1：X必然为总牌数的约数
2)	根据条件2：对于写着数字i的牌，如果有counti张，那么 X 也必须是所有 counti的约数（计数工作可由collections.Counter（数组）这个函数完成）
3)	满足上述两条的最大公约数X>= 2，则true

### 代码

```python

from collections import Counter
from fractions import gcd
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        N=len(deck) #数组长度为总牌数
        count=collections.Counter(deck) #数字i对应counti
        vals = count.values() #计数每个数字牌数（返回列表）
        vals.append(N)   #向列表加入单个元素
        return reduce(gcd, vals) >= 2
```