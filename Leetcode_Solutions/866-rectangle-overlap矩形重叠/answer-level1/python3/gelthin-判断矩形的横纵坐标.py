### 解题思路
首先保证 rec1 位于 rec2 的左侧。
若矩形最右边的横坐标 < 另一个矩阵最左边的横坐标
必然是输出 False
再接着判断。

不过我这里方法不好，逻辑混乱，写不出清晰的代码，且容易出错。缺少边界条件的判断。

##### 官方解法非常好：
官方题解下的评论: 计算机图形学基本算法，做 CV 的熟悉。
1. 判断什么时候不相交，固定一个矩阵，当另一个矩阵全位于一个矩阵的上方，下方，左方，右方时，就不想交。
2. 所谓的[IOU的基本解法，面试常用](https://leetcode-cn.com/problems/rectangle-overlap/solution/ju-xing-zhong-die-by-leetcode-solution/292243) ：IOU主要做目标检测，是由预测的包围盒与地面真相包围盒之间的重叠区域（交集）
+ 考虑如果矩阵相交，那么把两个矩阵都投影到 x 轴上，两个线段必然相交，投影到 y 轴上两个线段也必然相交
+ 考虑线段 (x1, x2), (x3, x4) 是否相交，相交 当且仅当  min(x2,x4) > max(x1,x3)
+ 考虑线段 (y1, y2), (y3, y4) 是否相交，相交 当且仅当  min(y2,y4) > max(y1,y3)
### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if (rec1[0], rec1[1]) == (rec1[2], rec1[3]):
            return False
        if (rec1[0], rec1[1]) == (rec1[2], rec1[3]):
            return False
        if rec1[0] > rec2[0]:
            rec1, rec2 = rec2, rec1  # 保证 rec1 左下角点 在 rec2 左侧或者 x 坐标相同
        # if rec1[3] <= rec2[0]:  ## 这里是 BUG
        if rec1[2] <= rec2[0]:   # 若矩形最右边的横坐标 < 另一个矩阵最左边的横坐标
            return False
        else:
            if rec2[3] <= rec1[1] or rec2[1] >= rec1[3]:
                return False
            else:
                return True
        
```