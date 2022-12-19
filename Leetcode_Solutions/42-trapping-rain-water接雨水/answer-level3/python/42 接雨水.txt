### 解题思路
寻找每个下标的左边和右边最高的柱子时，会对柱子进行反复搜索导致复杂度降低，假如我们使用两个数组 maxleft 和 maxright，maxleft[i] 表示下标 i 左边最高柱子的高度,maxright[i] 表示下标 i 右边最高柱子的高度，很明显，我们只需要一趟遍历就可以得到结果。这样由于避免了重复计算，时间复杂度会降低到 O(N)。


### 代码

```python
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height: return 0
        n = len(height)
        maxleft = [0] * n
        maxright = [0] * n
        ans = 0
        # 初始化
        maxleft[0] = height[0]
        maxright[n-1] = height[n-1]
        # 设置备忘录，分别存储左边和右边最高的柱子高度
        for i in range(1,n):
            maxleft[i] = max(height[i],maxleft[i-1])
        for j in range(n-2,-1,-1):
            maxright[j] = max(height[j],maxright[j+1])
        # 一趟遍历，比较每个位置可以存储多少水
        for i in range(n):
            if min(maxleft[i],maxright[i]) > height[i]:
                ans += min(maxleft[i],maxright[i]) - height[i]
        return ans




```