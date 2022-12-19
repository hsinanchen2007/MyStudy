### 解题思路
看了大家的思路，反面解法（判断什么情况下不相交）更为多见些。的确，正面情况的考虑容易漏掉一些情景。
下面这种解法在思路上简洁明了，从边平移到同一条数轴后的相交关系来判断两个区域是否相交。

首先我们考虑一个简单的问题：数轴上有两条线段。其中第一条从x1 -> x2, 第二条从x3 -> x4。已知x1 <= x2, x3 <= x4, 且x1 <= x3 （即第一条线段的左端点更靠左）。在什么情况下两条直线相交呢？

这个小问题的答案是显而易见的。如果x2 > x3, 则两条直线相交部分的线段长度不为0（x2=x3刚好重叠时不算）。我们通过一个`line_overlap`函数实现了这一判断。

再回过头来看原来的问题。我们同样可以对y的情况进行（平移到x相同的情况以后）线段重叠的判断。两个矩形有相交面积，当且仅当它们y_overlap并且x_overlap。


### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1_1, y1_1, x2_1, y2_1 = rec1
        x1_2, y1_2, x2_2, y2_2 = rec2
        if self.line_overlap(x1_1, x2_1, x1_2, x2_2) and \
            self.line_overlap(y1_1, y2_1, y1_2, y2_2):
            return True
        else:
            return False

    def line_overlap(self, x1, x2, x3, x4):
        # line1: x1 -> x2, line2: x3 -> x4
        if x1 > x2:
            x1, x2 = x2, x1
        if x3 > x4:
            x3, x4 = x4, x3
        if x1 > x3:
            x1, x2, x3, x4 = x3, x4, x1, x2
        # assert x1 <= x2 and x3 <= x4
        # assert x1 <= x3
        if x2 > x3:
            return True
        return False

```