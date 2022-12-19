双百

### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def cutSquares(self, square1, square2):
        """
        :type square1: List[int]
        :type square2: List[int]
        :rtype: List[float]
        """
        m1 = (square1[0]+square1[2]/2.0, square1[1]+square1[2]/2.0)
        m2 = (square2[0]+square2[2]/2.0, square2[1]+square2[2]/2.0)
        print(m1, m2)
        if m1[0] == m2[0]:
            print(0)
            m1_lowest = square1[1]
            m1_highest = square1[1]+square1[2]
            m2_lowest = square2[1]
            m2_highest = square2[1]+square2[2]
            return [m1[0], min(m1_lowest, m2_lowest), m1[0], max(m1_highest, m2_highest)]
        elif abs((m1[1]-m2[1])/(m1[0]-m2[0]))<1:
            print(1)
            m1_right = (square1[0]+square1[2], m1[1]+float(m2[1]-m1[1])/(m2[0]-m1[0])*square1[2]/2.0)
            m1_left = (square1[0], m1[1]-float(m2[1]-m1[1])/(m2[0]-m1[0])*square1[2]/2.0)
            m2_right = (square2[0]+square2[2], m2[1]+float(m2[1]-m1[1])/(m2[0]-m1[0])*square2[2]/2.0)
            m2_left = (square2[0], m2[1]-float(m2[1]-m1[1])/(m2[0]-m1[0])*square2[2]/2.0)
            if m1_right[0]>m2_right[0]:
                rightmost = m1_right
            else:
                rightmost = m2_right
            if m1_left[0]<m2_left[0]:
                leftmost = m1_left
            else:
                leftmost = m2_left
            return[leftmost[0], leftmost[1], rightmost[0], rightmost[1]]
        else:
            print(2)
            m1_up = (m1[0]+float(m2[0]-m1[0])/(m2[1]-m1[1])*square1[2]/2, square1[1]+square1[2])
            m1_down = (m1[0]-float(m2[0]-m1[0])/(m2[1]-m1[1])*square1[2]/2, square1[1])
            m2_up = (m2[0]+float(m2[0]-m1[0])/(m2[1]-m1[1])*square2[2]/2, square2[1]+square2[2])
            m2_down = (m2[0]-float(m2[0]-m1[0])/(m2[1]-m1[1])*square2[2]/2, square2[1])
            if m1_up[1]>m2_up[1]:
                upmost = m1_up
            else:
                upmost = m2_up
            if m1_down[1]<m2_down[1]:
                downmost = m1_down
            else:
                downmost = m2_down
            if upmost[0]<downmost[0]:
                return upmost+downmost
            else:
                return downmost+upmost
```