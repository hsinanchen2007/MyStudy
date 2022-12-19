### 解题思路
矩形想交的情况分几种：但是都必须满足以下两个条件
    第一个矩形的左下角和第二个举行右上角能组成一个矩形
    第二个矩形的左下角和第一个举行右上角能组成一个矩形

### 代码

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        

        return rec1[0]<rec2[2] and rec1[1]<rec2[3] and rec2[0]<rec1[2] and rec2[1]<rec1[3]
            
```