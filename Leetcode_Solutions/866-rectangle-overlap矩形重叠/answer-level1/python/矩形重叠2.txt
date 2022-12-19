### 解题思路
简单的重叠与不重叠的判断，条件很多，这一点还需要学习。

### 代码

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        if rec1[0]<rec2[0] and rec1[1]<rec2[1] and rec2[2]<rec1[2] and rec2[3]<rec1[3]:
            return True
        elif (rec1[2]-rec2[0])*(rec1[3]-rec2[1])<=0 or (rec2[2]-rec1[0])*(rec2[3]-rec1[1])<=0 or (rec2[2]-rec1[0])*(rec1[3]-rec2[1])<=0 or (rec1[2]-rec2[0])*(rec2[3]-rec1[1])<=0:
            return False
        else:
            return True

```