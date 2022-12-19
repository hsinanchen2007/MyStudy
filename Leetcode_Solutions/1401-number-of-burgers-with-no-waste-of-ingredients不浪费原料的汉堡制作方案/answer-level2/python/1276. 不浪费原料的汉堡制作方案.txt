### 解题思路
首先以奶酪的数决定巨无霸的个数，那么小汉堡 = [所需番茄数-现有番茄数]/2,对此值进行判断即可

### 代码

```python
class Solution(object):
    def numOfBurgers(self, tomatoSlices, cheeseSlices):
        #假设全部做成巨无霸
        sub = 4 * cheeseSlices - tomatoSlices
        if sub < 0:return []
        elif sub % 2 != 0 or sub / 2 > cheeseSlices:
            return []
        else:
            return [cheeseSlices - int(sub/2),int(sub/2)]
```