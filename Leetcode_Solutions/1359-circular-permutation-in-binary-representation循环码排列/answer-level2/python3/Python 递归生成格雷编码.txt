![image.png](https://pic.leetcode-cn.com/258f3a32fee6feaca1322e0a387a1ed52d20c43dee5caf766f35bd0347e70295-image.png)


```
'''
递归生成格雷编码，然后查找起始数值的位置
'''

from typing import List
class Solution:

    def getList(self, n):
        if n == 1:
            return [0, 1]

        l = self.getList(n-1)
        return l + [x + (1<<(n-1)) for x in reversed(l)]

    def circularPermutation(self, n: int, start: int) -> List[int]:
        data = self.getList(n)
        pos = -1
        for i in range(1<<n):
            if start == data[i]:
                pos = i
                break
        return data[pos:] + data[: pos]
```
