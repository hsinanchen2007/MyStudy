### 解题思路
不相交就这四种情况，分别是：
1.矩阵1的x最小值大于等于矩阵2的x最大值
2.矩阵1的y最小值大于等于矩阵2的y最大值
3.矩阵2的x最小值大于等于矩阵1的x最大值
4.矩阵2的y最小值大于等于矩阵1的y最大值
![8B81}J9Z\[N(F`88POA1ZKPA.png](https://pic.leetcode-cn.com/b6a7897193b36dcb4645c30bec1739a179a3220ec574c1b2a89c4fb12348d805-8B81%7DJ9Z%5BN\(F%6088POA1ZKPA.png)


### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[2] <= rec2[0] or rec2[2] <= rec1[0]:
            return False
        elif rec1[3] <= rec2[1] or rec2[3] <= rec1[1]:
            return False
        else:
            return True
```