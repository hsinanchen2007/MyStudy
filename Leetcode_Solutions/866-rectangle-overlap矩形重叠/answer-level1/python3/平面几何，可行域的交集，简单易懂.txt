### 解题思路
乍一看，要考虑的情况似乎很多，两矩形到底是怎么一个重叠情况也不清楚，一不小心就少考虑了一种。

事实上题目中的坐标系提醒了我，我们只要将这题中的两个矩形看成是两个可行域，求这两个可行域的交集，也就是最终的可行域即可。
![微信图片_20200318095330.jpg](https://pic.leetcode-cn.com/ebd11f48f1329029283fb3c3b57b1be10e066033d555dad2aa860a732fcfa60c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200318095330.jpg)

最终只要判断最终的可行域面积是否大于0即可

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:

        x1 = max(rec1[0], rec2[0])
        y1 = max(rec1[1], rec2[1])

        x2 = min(rec1[2], rec2[2])
        y2 = min(rec1[3], rec2[3])

        if x1 < x2 and y1 < y2:
            return True
        else:
            return False
```