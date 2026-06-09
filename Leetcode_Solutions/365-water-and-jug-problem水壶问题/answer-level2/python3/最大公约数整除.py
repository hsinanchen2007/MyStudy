
### 解题思路
首先分析后发现，可以可实现的 $ z = mx + ny $，其中 $ z >= 0, m,n$为整数，可能是负整数。分析过程就是在纸上写，发现 x-y 可以实现，那 y-(x-y)=2y-x 也可以实现（如果不小于0的话），其余以此类推。
如果 x, y的最大公约数也是 z 的因数，那么就有整数解 m,n，即可以实现 z 升水。一些细节是由于只有两个瓶，所以水量不可能超过两个瓶的容量。如果有一个专门用来装水的第三个瓶子，则只要 z % gca(x,y) == 0 即可实现z升水。
求 x, y 的最大公约数这里用了辗转相减法。
### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z < 0 or z > x+y:   # 特殊情形直接排除
            return False
        if x == 0 and y == 0:  # x==0, y==0, 则 z==0 才可能
            return z == 0

        zbase = self.gca(x, y) # 关键代码就2行
        return z % zbase == 0
    

    def gca(self, x, y): # 求最大公约数
        if x == 0:       # 特殊情形
            return y
        if y == 0:
            return x
 
        while x != y:    # 辗转相减
            x,y = max(x,y), min(x,y)
            x,y = y, x-y
        return x

```