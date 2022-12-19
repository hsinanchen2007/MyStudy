### 解题思路
1. 解题目标：
    - 两个矩形ab
    - 判断两个矩形是否相交
2. 解题思路：
    - 有哪些相交情况
    - 1
![微信图片_20200318115300.png](https://pic.leetcode-cn.com/a08439ff3479cdd8f0457b4fb6fe1a592abe803aeb3993a70afb775e985afa89-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200318115300.png)
    - 2
![微信图片_20200318115307.png](https://pic.leetcode-cn.com/98f2f38258dc1f149ede9bcb74fd02abf8cd3b73ec0607d0d6711db6d6a6c3ea-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200318115307.png)
    - 相交情形一：角在矩形中
        - 找到a的4个角的坐标
        - 判断坐标是否在b中
        - 找到b的4个角的坐标
        - 判断坐标是否在b中
    - 相交情形二：角不在矩形中，区域重叠
        - a的左在[b左，b右]，a的右在[b左，b右]
        - a的下在[b下，b上]，a的右在[b下，b上]

### 代码

```python3

class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return self.is_cross(rec1,rec2) or self.is_cross(rec2,rec1)
    
    #rec1是否在rec2中
    def is_cross(self,rec1,rec2):
        #重叠
        if rec1[0] >= rec2[0] and rec1[1] <= rec2[1] and rec1[2] <= rec2[2] and rec1[3] >= rec2[3]:
            return True
        #左上
        left_up = [rec1[0],rec1[3]]
        if left_up[0] > rec2[0] and left_up[0] < rec2[2] and left_up[1] > rec2[1] and left_up[1] < rec2[3]:
            return True
        #右上
        right_up = [rec1[2],rec1[3]]
        if right_up[0] > rec2[0] and right_up[0] < rec2[2] and right_up[1] > rec2[1] and right_up[1] < rec2[3]:
            return True
        #左下
        left_down = [rec1[0],rec1[1]]
        if left_down[0] > rec2[0] and left_down[0] < rec2[2] and left_down[1] > rec2[1] and left_down[1] < rec2[3]:
            return True
        #右下
        right_down = [rec1[2],rec1[1]]
        if right_down[0] > rec2[0] and right_down[0] < rec2[2] and right_down[1] > rec2[1] and right_down[1] < rec2[3]:
            return True
        return False

        







```