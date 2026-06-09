题目明确x1,y1是左下角坐标，x2,y2是右上角坐标，ok，get到关键点，来解题，题解里很多大佬给出了投影的方法去理解，我这边给出另外一种直观的解释

首先假定第一个矩形不动，我们去放第二个矩形，怎么样才能重叠？
第一个矩形为A，第二个矩形为B，固定A，若两者需要重叠，则B的左下角B1点必须在下图中的红色阴影区域内（取开区间，因为只有一条边或点重叠时不算）。若在阴影外则A和B必然不会重合。这是一个必要条件。
即：rec2[0] < rec1[2] and rec2[1] < rec1[3]
![题解1.png](https://pic.leetcode-cn.com/5f21dfaadebb0924c0399db235aa454fc56664efaf199c6756110b2700adb1f9-%E9%A2%98%E8%A7%A31.png)
同理，仍然固定A，考虑两个矩形重叠，对于第二个矩形B来说，右上角的点也有类似限制。矩形B右上角的点B2必须在红色阴影区域内(不含边界)，两矩形才有可能重合，这也是一个必要条件。
即：rec2[2] > rec1[0] and rec2[3] > rec1[1]
![题解3.png](https://pic.leetcode-cn.com/84bc27b501e5a778f71149e00dd4ac3e81e4de340b6521637910cf5a747af209-%E9%A2%98%E8%A7%A33.png)

两个必要条件缺一不可，所以用and连起来两个条件就是该题的解必须满足的条件。
那么如何论证其充分性呢？其实在最前面的一个特点已经保证了题解的充分性，题目限定第一组坐标为左下角点，第二组为右下角点。

最后贴代码：
```
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return rec2[0] < rec1[2] and rec2[1] < rec1[3] and rec2[2] > rec1[0] and rec2[3] > rec1[1]
```

