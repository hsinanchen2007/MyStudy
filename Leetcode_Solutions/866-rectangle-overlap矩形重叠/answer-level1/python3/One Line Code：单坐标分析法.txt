### 解题思路
此处撰写解题思路
    设 x1,x2 为矩形1的横坐标集；x3,x4为矩形2的横坐标集
    从x轴看：        
    √  相交，则必有交集。 形象表示： x1 x3 <交集> x2 x4。 这里使用max min避免考虑矩形左右的问题
    同理y轴。
### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: list(), rec2: list()) -> bool:
        return True if max(rec1[0],rec2[0]) < min(rec1[2],rec2[2]) and max(rec1[1],rec2[1])<min(rec1[3],rec2[3]) else False
```