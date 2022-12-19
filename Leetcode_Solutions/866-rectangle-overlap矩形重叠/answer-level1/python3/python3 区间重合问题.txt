```
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # 首先rec的前面的左下角的坐标肯定是小于右上角的坐标的，如果确保是一个有面积的矩形而不是一条边的话。
        # 分成rec 的x范围和 y的范围，只有两个rec的，x和y的范围都有交集，才说明矩形有重合

        rec1_x = rec1[0],rec1[2]
        rec1_y = rec1[1],rec1[3]

        rec2_x = rec2[0],rec2[2]
        rec2_y = rec2[1],rec2[3]

        def helper(range1,range2):
            b1,t1 = range1
            b2,t2 = range2

            if t1<=b2 or t2<=b1:
                return False
            else:
                return True
        
        return helper(rec1_x,rec2_x) and helper(rec1_y,rec2_y)




```