### 解题思路
利用斜率，为了避免分母为0 全部变为乘法

### 代码

```python
class Solution(object):
    def checkStraightLine(self, coordinates):
        if len(coordinates) == 2:
            return True
        k = coordinates[0][1] - coordinates[1][1]
        b = (coordinates[0][0] - coordinates[1][0])*coordinates[0][1] - k*coordinates[0][0]
        for i in range(2,len(coordinates)):
            if k*coordinates[i][0] - (coordinates[0][0] - coordinates[1][0])*coordinates[i][1] + b != 0:
                return False
        return True
```