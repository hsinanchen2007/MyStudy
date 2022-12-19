### 解题思路
大家应该都知道韦恩图是什么，由此启发可以得到本题思路。
（借用官方图例）
如下图，从左往右遍历，不管是雨水还是柱子，都计算在有效面积内，并且每次累加的值根据遇到的最高的柱子逐步上升。面积记为S1。
![image.png](https://pic.leetcode-cn.com/60f50754e0b15a27def14e54887a357c7f16dd0c7f767e963fc306144c3d16e1-image.png)
从左往右遍历得S1，每步S1+=max1且max1逐步增大

同样地，从右往左遍历可得S2。
![image.png](https://pic.leetcode-cn.com/2749a1e1805a9f22bba66e259f75c95cdab5d36413ee47b7f923107ff49583d0-image.png)
从右往左遍历得S2，每步S2+=max2且max2逐步增大

于是我们有如下发现，S1 + S2会覆盖整个矩形，并且：重复面积 = 柱子面积 + 积水面积
![image.png](https://pic.leetcode-cn.com/a20ea5560f99de54f6dcd508e72d8527da74a39bb51e1e98f4f6621fc8aa1451-image.png)

最终， 积水面积 = S1 + S2 - 矩形面积 - 柱子面积
### 代码

```python
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        # 同时从左往右和从右往左计算有效面积
        s1, s2 = 0, 0
        max1, max2 = 0, 0
        for i in range(n):
            if height[i] > max1:
                max1 = height[i]
            if height[n - i - 1] > max2:
                max2 = height[n - i - 1]
            s1 += max1
            s2 += max2
        # 积水面积 = S1 + S2 - 矩形面积 - 柱子面积
        res = s1 + s2 - max1 * len(height) - sum(height)
        return res
```