### 解题思路
初始方向为左，拐点处换方向，画出一棵看起来很深的树（每个节点只有不多于1个后继节点）。从上至下发现有`numRows`列，以列号编号，发现从上到下呈现出`0 1 2 3 ... numRows-1 numRows-2 ... 3 2 1 0 1 2 3 ... numRows-1 ... 3 2 1 0 ...`，我们只需按序号从上到下将各字符放入`numRows`个的数组中即可。

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        ans = [[] for i in range(numRows)]
        i = 0
        dire = 1
        if numRows == 1:
            return s
        for char in s:
            ans[i].append(char)
            if i == numRows-1:
                dire = -1
            if i == 0:
                dire = 1
            i += dire
        rst = []
        return ''.join(list(map(''.join ,ans)))
```