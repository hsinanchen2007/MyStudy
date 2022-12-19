### 解题思路

本题相比 [836. 矩形重叠](https://leetcode-cn.com/problems/rectangle-overlap/) 难度提升了一级。

我们很容易想到应该使用划分区域的方法，划分区域的方法有很多，这里介绍其中一种方法。

将矩形分为9个区域，判定圆心的位置在哪个区域：
- 如果圆心在矩形的内部，则一定相交；

- 如果圆心位于矩形的上下左右四个区域当中，检测圆心到边的距离，判定是否相交；

- 如果圆心位于四个角对应的区域，只要检测矩形的四个顶点是否在圆的内部即可。

![](https://pic.leetcode-cn.com/8765b36bd0f3bc3c84fd598f16dd01a6112e081adc66325a48718e89b1e474a7-TIM%E6%88%AA%E5%9B%BE20200404235733.png)


### 代码
```python []
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # 条件 1：首先判断圆心是否在矩形内
        if x1 <= x_center <= x2 and y1 <= y_center <= y2:
            return True
        # 条件 2：圆心位于矩形的上下左右四个区域
        elif x_center > x2 and y1 <= y_center <= y2: # 右
            return radius >= x_center - x2
        elif y_center < y1 and x1 <= x_center <= x2: # 下
            return radius >= y1 - y_center
        elif x_center < x1 and y1<= y_center <= y2: # 左
            return radius >= x1 - x_center
        elif y_center > y2 and x1 <= x_center <= x2: # 上
            return radius >= y_center - y2
        else:
        # 条件 3：判断矩形的四个顶点是否在圆的内部
            return min((x1 - x_center) ** 2 + (y2 - y_center) ** 2,\
                       (x2 - x_center) ** 2 + (y2 - y_center) ** 2, \
                       (x2 - x_center) ** 2 + (y1 - y_center) ** 2, \
                       (x1 - x_center) ** 2 + (y1 - y_center) ** 2) <= radius ** 2
```
### 复杂度分析
- 时间复杂度：$O(1)$。
- 空间复杂度：$O(1)$。