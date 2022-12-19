### 解题思路
排除掉三种不相交的可能性即可

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        #rec1:(rec1[0],rec1[1])左下 (rec1[0],rec1[3])左上
        ##  (rec1[2],rec1[1])右下 (rec1[2],rec1[3])右上
        #rec2:(rec2[0],rec2[1])左下 (rec2[0],rec2[3])左上
        ##  (rec2[2],rec2[1])右下 (rec2[2],rec2[3])右上        
        if [rec1[0],rec1[1]]==[rec2[0],rec2[0]] or [rec1[2],rec1[3]]==[rec2[2],rec2[3]]:
            return True
        elif [rec1[0],rec1[1]]>[rec2[0],rec2[0]]: #rec1靠左下 rec2靠右上
            rec1,rec2=rec2,rec1
        if rec1[0]==rec2[0]:##1,2在同一纵坐标 只考虑上下
            if rec1[3]<=rec2[1]:
                return False
            else:
                return True
        else:##1在2的左边
            if rec1[2]<=rec2[0] or rec1[1]>=rec2[3] or rec1[3]<=rec2[1] :
                return False
            else:
                return True
        

```