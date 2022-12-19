### 解题思路
已知:
点1,点2 = 矩形1 
点3,点4 = 矩形2

开始以为是判断两个矩形的重叠面积是否为正方形,那就是

判断4点共线 and (点3或点4)在点1和点2的线段内..

那么就是正方形了..

正准备写代码,才发现是两个矩形有重叠部分即可..哈哈那么思路就简单了
排除所有不可能,剩下的就是可能:
    
点3比点2大,或者点4比点1小都不重叠,
排除这个两种情况,即可


### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1,y1,x2,y2 = rec1
        x3,y3,x4,y4 = rec2
        return not(x3>=x2 or x4<=x1 or y3>=y2 or y4<=y1)
        
```