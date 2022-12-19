这个题目用短路的思路比较偏，所以还不如练习一下Python的高级函数reduce（Python3需要导包，Python还是直接用），这个函数在面试中也是经常被问到的，贴上来供大家参考：

```
from functools import reduce
class Solution:
    def sumNums(self, n: int) -> int:
        return reduce(lambda x, y: x+y, [i for i in range(1,n+1)])
```
