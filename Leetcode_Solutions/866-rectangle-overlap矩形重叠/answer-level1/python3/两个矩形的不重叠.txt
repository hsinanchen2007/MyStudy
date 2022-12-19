两个矩形的不重叠分两种情况：
1）上下不重叠，即y坐标不重合
2）左右不重叠，即x坐标不重合
代码如下：
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        #两个矩形上下不重叠：一个矩形的右上角y轴坐标，小于等于另一个矩形左下角y轴坐标，则不重叠
        if rec1[3] <= rec2[1] or rec2[3] <= rec1[1]:
            return False
        #两个矩形左右不重叠：若一个矩形的右上角x轴坐标，小于等于另一个矩形左下角x轴坐标，则不重叠
        elif rec1[2] <= rec2[0] or rec2[2] <= rec1[0]:
            return False
        else:
            return True
