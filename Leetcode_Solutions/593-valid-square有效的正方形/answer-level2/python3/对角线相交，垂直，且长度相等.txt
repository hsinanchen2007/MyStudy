```
# https://leetcode-cn.com/problems/valid-square/
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        l12 = [a - b for a, b in zip(p1, p2)]
        l13 = [a - b for a, b in zip(p1, p3)]
        l14 = [a - b for a, b in zip(p1, p4)]
        l23 = [a - b for a, b in zip(p2, p3)]
        l24 = [a - b for a, b in zip(p2, p4)]
        l34 = [a - b for a, b in zip(p3, p4)]

        s12 = [a + b for a, b in zip(p1, p2)]
        s13 = [a + b for a, b in zip(p1, p3)]
        s14 = [a + b for a, b in zip(p1, p4)]
        s23 = [a + b for a, b in zip(p2, p3)]
        s24 = [a + b for a, b in zip(p2, p4)]
        s34 = [a + b for a, b in zip(p3, p4)]

        def check_perpendicular(l1, l2):
            if l1 == [0, 0]:
                return False
            return (l1[0] == l2[1] and l1[1] + l2[0] == 0) or (l1[0] + l2[1] == 0 and l1[1] == l2[0])

        def check_intersection(s1, s2):
            return s1 == s2

        return check_perpendicular(l12, l34) and check_intersection(s12, s34) or \
               check_perpendicular(l13, l24) and check_intersection(s13, s24) or \
               check_perpendicular(l14, l23) and check_intersection(s14, s23)

```
向量长度相等且垂直，由check_perpendicular判断
相交由check_intersection（中点相同）保证

