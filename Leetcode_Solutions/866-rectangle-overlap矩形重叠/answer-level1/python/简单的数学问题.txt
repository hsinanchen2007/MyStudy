### 解题思路
重叠即横纵坐标交集不为空
设第一个矩阵x的范围[a1,b1],纵坐标[c1,d1]
第二个矩阵x的范围[a2,b2],纵坐标[c2,d2]
要有重叠，则[a1,b1]和[a2,b2]取交集不为空集，[c1,d1]和[c2,d2]取交集不为空集，
不为空集那就是a1必须小于b2，b1必须大于a2，纵坐标同理


### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return rec1[0]<rec2[2] and rec2[0]<rec1[2] and rec1[1]<rec2[3] and rec2[1]<rec1[3]
```