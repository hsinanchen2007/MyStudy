### 解题思路
1. 拥有相同斜率，即在一条直线上。
2. 任意三点`(x1,y1),(x2,y2),(x3,y3)`如果满足`(x2-x1)/(y2-y1) = (x3-x2)/(y3-y2)`则这三点在一条直线上。
3. 由于被除数不能为零，即转化成判断`(x2-x1)*(y3-y2) == (x3-x2)*(y2-y1)`。

### 代码

```python3
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        def calculate_k_b(coordinates1, coordinates2):
            x1, y1 = coordinates1[0],coordinates1[1]
            x2, y2 = coordinates2[0],coordinates2[1]

            if (x1-x2) != 0:
                k = (y1-y2)/(x1-x2)
                b = y1-k*x1
            else:
                k,b = 0, x1
            print(k,b)
            return k,b
        
        k,b = calculate_k_b(coordinates[0],coordinates[1])

        for item in coordinates[2:len(coordinates)]:
            x,y = item[0],item[1]
            if y != x*k + b:
                print(y)
                print(x*k + b)
                return False
        
        return True
        
```