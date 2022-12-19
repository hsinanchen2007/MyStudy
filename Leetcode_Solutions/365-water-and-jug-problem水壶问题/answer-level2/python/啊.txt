### 解题思路
虽然写的复杂了，但这个题思路主要在将一个结果看成一个过程，这个过程中往杯子中倒水属于加法，倒去杯子水属于减法，而加谁和减谁是什么，思考清楚就好了

### 代码

```python3
def getMaxcommpisor(a,b):
    if a < b:
        a,b = b,a     #保证a大于b
    while a%b != 0:
        a,b = b,a%b
    return b

class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z == 0:
            return True
        if x>y:
            big = x
            small = y
        else:
            big = y
            small = x
        if big == 0:
            if z == 0:
                return True
            else:
                return False
        if small == 0:
            if z == big :
                return True
            else:
                return False
        if z > big + small:
            return False
        need = getMaxcommpisor(big,small)
        if z % need == 0:
            return True
        else :
            return False
        
        
```