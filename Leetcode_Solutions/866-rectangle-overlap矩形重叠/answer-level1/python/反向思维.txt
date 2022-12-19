### 解题思路
刚开始是想，考虑什么情况下它们重叠，但这类情况非常复杂，所以从另一方面来说，考虑什么情况它们不重叠，即可简化为四种情况:
1. 当A1完全在A2的最左边时；
2. 当A1完全在A2的最右边时；
3. 当A1完全在A2的最上边时；
4. 当A1完全在A2的最下边时。
其他的情况即是重叠状况
### 代码

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        x1_left,x1_right,y1_down,y1_up=rec1[0],rec1[2],rec1[1],rec1[3]
        x2_left,x2_right,y2_down,y2_up=rec2[0],rec2[2],rec2[1],rec2[3]
        if x1_right<=x2_left or x1_left>=x2_right or y1_down>=y2_up or y1_up<=y2_down:
            return False
        return True
        
```