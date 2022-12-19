### 解题思路
贪心算法，以区间结尾排序
如果cur_end 小于 下一个的start，那箭数+1。
注意：要讨论points为0的情况

### 代码

```python
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if not points:
            return 0
            
        points.sort(key=lambda x:x[1])
        cur_end = points[0][1]
        arrows = 1
        for begin,end in points:
            if cur_end < begin:
                arrows += 1
                cur_end = end
            else:
                pass
        return arrows

```