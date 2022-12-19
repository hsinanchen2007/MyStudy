### 解题思路
解题思路：双指针,时间复杂度O(n),空间复杂度O(1)
第一步：双指针分别指向列表的两端
第二步：计算两个指针位置中间的面积，更新最大面积
第三步：更新指针，指针位置高度较低的更新
思路：最大面积要求，宽度足够大，两个边界的高度足够高
### 代码

```python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        lowP = 0
        highP = len(height) - 1
        res = 0

        while lowP < highP:
            h = min(height[lowP], height[highP])
            w = highP - lowP

            res = max(res, h * w)

            if height[lowP] < height[highP]:
                lowP += 1
            else:
                highP -= 1

        return res
```