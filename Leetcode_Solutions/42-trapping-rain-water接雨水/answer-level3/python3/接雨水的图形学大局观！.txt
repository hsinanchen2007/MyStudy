* 观察下图，我们把填充好的这张图想象成一座山，从左到右，我们经历了**上坡**和**下坡**两个阶段。
![](https://pic.leetcode-cn.com/cbfb530161721a646223de525316df1d3385741d2567a05915663bf88c1bab94.png)
* 再考虑另一种情况，如果最高点不止一个，那么填充之后，我们需要走三段路：**上坡，平地和下坡**。
* 仔细想想，无论高度图原来是什么样子，经过雨水填充后，一定都是可以分成这三段路（两段作为平地为0的特殊情况）。
* 所以算法来了：
    * 首先找到最高高度`max_height`，令最左边高度为`max_height`的位置为`start`，令最右边高度为`max_height`的位置为`end`，即`start`和`end`是平地的两端。那么`height`被分为了三段：(1)`0`到`start-1`; (2)`start`到`end`;（3）`end+1`到`len(height)-1`。这三段我们分别进行处理。
        * 从`0`向`start-1`遍历：记录历史最高高度`curr_max`。如果`height[i]`更高，`curr_max = height[i]`；否则，水量增加二者的差值。
        * 从`len(height)-1`向`end+1`倒着遍历：方法同上。
        * 从`start`向`end`：水量增加`max_height - height[i]`。
* 时间复杂度： O(n)；空间复杂度 O(1)。

```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <= 2:
            return 0
        max_height = max(height)
        start = height.index(max_height)
        end = len(height) - height[::-1].index(max_height) - 1
        water = 0
        curr_max = 0
        for i in range(start):
            if height[i] > curr_max:
                curr_max = height[i]
            else:
                water += curr_max - height[i]
        curr_max = 0
        for i in range(len(height)-1, end, -1):
            if height[i] > curr_max:
                curr_max = height[i]
            else:
                water += curr_max - height[i]
        for i in range(start, end):
            water += max_height - height[i]
        return water
```

* 提交成功后，我也学习了大家的解法，方法看似五花八门，但它们之间的逻辑非常清楚，大体可以分为如下两类：
* 第一类：从暴力法一步步进行优化。 [labuladong](https://leetcode-cn.com/problems/trapping-rain-water/solution/tu-jie-jie-yu-shui-dong-tai-gui-hua-he-shuang-zhi-/)给出了很贴心的梳理。暴力法的思想是这些方法的underlying knowledge。但我连暴力法的逻辑都没想到（…）。所以就采用的是一条和大家都不同的路啦。ps: 以下方法参考自[官方题解](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/)、[labuladong](https://leetcode-cn.com/problems/trapping-rain-water/solution/tu-jie-jie-yu-shui-dong-tai-gui-hua-he-shuang-zhi-/)和[liweiwei](https://leetcode-cn.com/problems/trapping-rain-water/solution/bao-li-jie-fa-yi-kong-jian-huan-shi-jian-zhi-zhen-/)。
    1. **暴力法**：设位置`i`其左边柱子的最高高度为` l_max `，其右边柱子的最高高度为` r_max `，则位置 i 最大的水柱高度就是 `min(l_max, r_max)-height[i]`。所以，对于每个位置`i`，找到两边的`max`即可。
        * 时间复杂度： O(n^2)；空间复杂度 O(1)。
    2. **动态规划**：备忘录优化，即开两个数组`r_max`和`l_max`充当备忘录，用空间换时间。如下是[官方题解](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/)的配图，太形象了。
        * 时间复杂度： O(n)；空间复杂度 O(n)。![](https://pic.leetcode-cn.com/53ab7a66023039ed4dce42b709b4997d2ba0089077912d39a0b31d3572a55d0b-trapping_rain_water.png)
    3. **双指针**：在动态规划的基础上继续优化空间。让两个指针从两头相向而行，边走计算，只需遍历一次。下面给出双指针的实现。
        * 时间复杂度： O(n)；空间复杂度 O(1)。
```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <= 2:
            return 0
        left, right = 0, len(height)-1
        l_max, r_max = height[left], height[right]
        water = 0
        while(left < right):
            if l_max < r_max:
                water += l_max - height[left]
                left += 1
                l_max = height[left] if height[left] > l_max else l_max
            else:
                water += r_max - height[right]
                right -= 1
                r_max = height[right] if height[right] > r_max else r_max
        return water
```

* 第二类：借助栈，也蛮有意思的。可参考[windliang](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)的解法。时间复杂度： O(n)；空间复杂度 O(n)。