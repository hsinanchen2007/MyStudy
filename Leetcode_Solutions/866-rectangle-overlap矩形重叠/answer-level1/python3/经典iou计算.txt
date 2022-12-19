### 解题思路
解这道题只需要三步
1.找到x1,y1的最大值
2.找到x2,y2的最小值
3.求相交面积，大于0 就是True 注意要和0比较一下 防止重合或者无交集的情况
### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1 = max(rec1[0],rec2[0])
        y1 = max(rec1[1],rec2[1])
        x2 = min(rec1[2],rec2[2])
        y2 = min(rec1[3],rec2[3])

        insert = max(x2-x1,0) *  max(y2-y1,0)
        if insert > 0:
            return True
        else:
            return False  


```