
**法一**
```
class Solution:
    def countAndSay(self, n: int) -> str:
        init = '1'
        for _ in range(n-1):
            flag, count, s = init[0], 0, ''  # flag在遇到不同字符的时候会改变，否则就一直计数
            for i in range(len(init)):
                if init[i] == flag:  # 从init的第一位开始比较，若相同就计数
                    count += 1
                else:  # 若不同，先记录第一个字符的统计结果，再改变flag的值
                    s += (str(count)+flag)
                    flag, count= init[i], 1
            s += (str(count)+flag)  # 处理最后一个字符
            init = s
        return init
```

**法二**

```
from itertools import groupby

class Solution:  # 不是我写的，我只是记录一下玩儿玩儿，哈哈
    def countAndSay(self, n: int) -> str:
        result = '1'
        for i in range(1, n):
            result = ''.join([str(len(list(g))) + k for k, g in groupby(result)])
        return result
```
