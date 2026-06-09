class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[0]<rec2[2] and rec1[2]>rec2[0]:
            if rec2[3]>rec1[1] and rec2[1]<rec1[3]:
                return True
        return False