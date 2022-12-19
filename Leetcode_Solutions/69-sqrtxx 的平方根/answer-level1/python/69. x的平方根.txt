### 解题思路
牛顿法正解。

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        # newton法
        pre = 1 #初值
        cur = 1/2*(pre+x/pre)
        while abs(cur-pre)>1e-6:
            pre = cur
            cur = 1/2*(pre+x/pre)
        return int(cur)

```