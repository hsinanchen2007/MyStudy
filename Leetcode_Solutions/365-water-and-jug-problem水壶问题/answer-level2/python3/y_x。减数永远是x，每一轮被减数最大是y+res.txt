### 解题思路
此处撰写解题思路
1.不失一般性，设y>x
2.第一轮最大容量为maxv = x+y
3.maxv不断减去x。最后剩下res1倒入x中。
4.y重新倒满，这一轮最大容量maxv = y + res1
5.y不断倒入x，即最大容量maxv不断减去x
6.得到新的res，返回第3步。直到res = 0为止
### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        a, b = max(x,y), min(x,y)
        if z == 0:
            return True
        if b == 0:
            if z == x or z == y:
                return True
            else:
                return False
        
        res = b
        while res != 0:
            for i in range(a + res, -1, -b):
                if z==i: 
                    return True
                res = i
        return False

```