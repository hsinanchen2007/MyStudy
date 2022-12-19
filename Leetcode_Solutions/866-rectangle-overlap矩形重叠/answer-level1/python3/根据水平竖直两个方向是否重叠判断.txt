### 解题思路
投影到两条坐标轴上，如果两个方向都有重叠，则两个矩形有重叠；反之则没有重叠。

重叠的清醒有好几种，或相交，或包含。但不重叠的情况比较简单，所以这里逆向思考了，以是否不重叠作为判断依据。

不重叠的情况比较好写：第一个的左下角的横坐标 >= 第二个的右上角的横坐标，或者反过来，就是x轴方向不重叠了。（注意等于的情况，对应共边，也是不重叠）

y轴方向同理。

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        horizontal, vertical = True, True
        if (rec2[0] >= rec1[2]) or (rec2[2] <= rec1[0]):
            horizontal = False
        if (rec2[1] >= rec1[3]) or (rec2[3] <= rec1[1]):
            vertical = False
        return horizontal and vertical
```