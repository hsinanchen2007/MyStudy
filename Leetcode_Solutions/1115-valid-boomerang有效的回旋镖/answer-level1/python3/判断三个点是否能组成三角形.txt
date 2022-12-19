这道题其实就是问给定的三个点能否组成一个三角形。设A(x1,y1),B(x2,y2),C(x3,y3)，则ABC组成的三角形面积 S=(1/2) * (下面行列式）：  
|x1 y1 1|  
|x2 y2 1|  
|x3 y3 1|  
即 S=(1/2) * (x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)=(1/2) * (x1y2+x2y3+x3y1-y1x2-y2x3-y3x1)。  
所以我们只需根据上式判断所给三个点组成的三角形的面积是否为0即可。   
```Python
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        (x1,y1),(x2,y2),(x3,y3) = points
        return (x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1) != 0
```