### 解题思路
逆向思维，考虑不重叠的情况即可，代码简单易懂，可以在脑子里思考整个过程

### 代码

```

class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        ##rec1的四个坐标
        x1_1 = rec1[0]
        y1_1 = rec1[1]
        x2_1 = rec1[2]
        y2_1 = rec1[3]
        ##rec2的四个坐标
        x1_2 = rec2[0]
        y1_2 = rec2[1]
        x2_2 = rec2[2]
        y2_2 = rec2[3]

        ##逆向思维：考虑不重叠的情况，剩下的就是重叠的情况：
        ###不重叠：分为左右不重叠和上下不重叠两种情况
        ##左右不重叠：x2_1 < x1_2 或者 x2_2 < x1_1
        ##上下不重叠：y2_1 < y1_2 或者 y2_2 < y1_1
        if x2_1<=x1_2 or x2_2 <= x1_1 or y2_1 <= y1_2 or y2_2 <= y1_1: ##因为不能重叠，所以取等号，相等的情况是不行的
            return False
        else:
            return True
        
```