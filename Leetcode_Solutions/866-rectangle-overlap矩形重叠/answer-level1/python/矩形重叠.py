因为重叠的情况比较复杂，所以我们选择取补集，也就是不重叠的情况
总共有四种情况：矩形2在矩形1的左边、右边、上边和下边，代码如下
"""
class Solution:  
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec2[2] <= rec1[0] or rec2[0] >= rec1[2] or rec2[1] >= rec1[3] or rec2[3] <= rec1[1]:
            return False
        return True
"""