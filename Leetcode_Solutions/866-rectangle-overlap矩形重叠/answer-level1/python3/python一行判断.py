```python
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # AL、AR分别表示A的左下角点和右上角点。BL、BR分别表示B的左下角点和右上角点
        # 当BL在AR的左下角，且BR在AL的右上角时，两矩形重叠
        # BLx < ARx and BLy < ARy
        # BLx:rec2[0]  BLy:rec2[1]  ARx:rec1[2]  ARy:rec1[3]
        # BRx > ALx and BRy > ALy
        # BRx:rec2[2]  BRy:rec2[3]  ALx:rec1[0]  ALy:rec1[1]
        if rec2[0] < rec1[2] and rec2[1] < rec1[3] and rec2[2] > rec1[0] and rec2[3] > rec1[1]:
            return True
        return False
```