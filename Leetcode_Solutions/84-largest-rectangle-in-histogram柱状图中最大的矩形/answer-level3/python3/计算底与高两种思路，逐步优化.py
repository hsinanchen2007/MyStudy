# 思路分析
矩形的面积由对应的底与高决定，在本题中可以分别考虑计算底与高的做法。

## 以bottom计算
### 暴力枚举
本题最简单的方法是直接暴力地枚举所有矩形的面积，并取最大值。在枚举矩形的时候，首先是枚举底长[i:j+1]，随后在底长范围中找到最低的高度min(h[i:j+1])作为矩形计算的面积。在这种计算方式下，相当于固定了bottom长度，随后计算在此bottom长度中能获得的最大面积。

```
class Solution1:
    def largestRectangleArea(self, heights: [int]) -> int:
        maxmun = 0
        for i in range(len(heights)):
            for j in range(i, len(heights)):
                s = (j-i+1) * min(heights[i:j+1])
                maxmun = max(maxmun, s)

        return maxmun
```

时间复杂度O(n³)，空间复杂度O(1)

### 动态规划优化最小值求解
注意到，min(h[i:j+1]) 的取值与min(h[i:j])有关，也就是说矩形中的最小高度可以通过递推计算而出，那么自然可以上动态规划来加速min(h[i:j+1])的求解。
```
使用dp数组存储min(h[i:j+1])，dp[i][j] 表示i~j中的最小高度
dp[i][j] = dp[i][j-1]     h[j] >= dp[i][j-1]
           h[j]           h[j] < dp[i][j-1] or i == j
```

```
class Solution2:
    def largestRectangleArea(self, heights: [int]) -> int:
        maxmun = 0
        dp = [[0 for i in range(len(heights))] for j in range(len(heights))]

        # dp计算最小高度
        for i in range(len(heights)):
            for j in range(i, len(heights)):
                if i == j or heights[j] < dp[i][j-1]:
                    dp[i][j] = heights[j]
                else:
                    dp[i][j] = dp[i][j-1]

                # 计算dp数组的同时也是在枚举[i:j]，因此可以将面积计算也合并到同一个循环之中。
                s = (j-i+1) * dp[i][j]   
                maxmun = max(maxmun, s)

        return maxmun
```

时间复杂度：O(n²) 空间复杂度O(n²)

### 动态规划空间优化
注意到dp[i][j]的计算只依赖于dp[i][j-1]，那么可以将二维dp直接压成一个变量，
```
class Solution2Optimized:
    def largestRectangleArea(self, heights: [int]) -> int:
        maxmun = 0
        
        # dp计算最小高度
        for i in range(len(heights)):
            min_height = 0
            for j in range(i, len(heights)):
                if i == j or heights[j] < min_height:
                    min_height = heights[j]

                s = (j-i+1) * min_height
                maxmun = max(maxmun, s)

        return maxmun
```

时间复杂度O(n²)，空间复杂度O(1)


## 以height计算
### 递归分治法
从上可以看出，矩形的面积取决于区间中最小的高度，因此考虑以拥有最小高度的点作为分治中心，将区域分为三份。
因此区间中的最大面积为
max(
    最小高度 * 区间长度，
    最小高度左侧的最大面积，
    最小高度右侧的最大面积
)

```
class Solution3:
    def largestRectangleArea(self, heights: [int]) -> int:
        def divide(left, right):
            if right < left:
                return 0

            min_i = left
            for i in range(left, right + 1):
                if heights[i] < heights[min_i]:
                    min_i = i

            return max((right - left + 1) * heights[min_i], 
                        divide(left, min_i-1), divide(min_i+1, right))
        return divide(0, len(heights) - 1)
```
如果在分治的过程中，如果能尽量将区间二分，那么对应的[主定理](https://zh.wikipedia.org/wiki/%E4%B8%BB%E5%AE%9A%E7%90%86)式为 T(n) = 2(n/2) + O(n)，对应的时间复杂度为O(nlogn)。
但是如果无法均分，例如数组降序的情况下，分治会退化为O(n²)

注意到，每次都会在区间中进行最小值查询，按照迭代算法需要O(n)来计算，那么可以借助[线段树](https://oi-wiki.org/ds/seg/)这一区间最值查找结构来讲区间查找的性能优化到O(logn)

对应的主定理式为T(n) = 2(n/2) + O(logn), 对应时间复杂度为θ(n)，如果二分不均，则会退化到O(nlogn)


### 中心扩展法
对于每个柱子，考虑以当前柱高h作为矩形中的最大高度来构建矩阵。如果临近的柱子柱高比h更大，那么矩形可以向外侧扩展。

例如对于[4,2,3], i=2时，由于h[0] < h[1] > h[2]，那么其左右端点可以延伸到left=0, right=2，即底长为2-0+1 = 3。
对于[4,2,1]，i=2时，由于h[0] < h[1] , h[2] > h[0]，那么左右端点为left=0, right=1，底长为1-0+1 = 2。

```
class Solution:
    def largestRectangleArea(self, heights: [int]) -> int:
        maxmun = 0

        for i in range(len(heights)):
            left, right = i, i
            while left > 0 and heights[left-1] >= heights[i]:
                left -= 1
            while right < len(heights)-1 and heights[right+1] >= heights[i]:
                right += 1
            
            s = (right - left + 1) * heights[i]
            maxmun = max(maxmun, s)

        return maxmun
```

时间复杂度O(n²)，空间复杂度O(1)

### 单调栈法
从中心扩展法可以发现，以height[i]构建矩形，其左右边界在坐标系中会显示为一个`倒V型`，如下图的蓝线部分；如果左右边界能向外扩展的话，那么会由中心向左单调递增，中心向右也呈现单调递增性，如下图红线部分的`类V型`。对于这种出现单调性的题目，通常可以考虑使用`单调栈`进行求解。
![image.png](https://pic.leetcode-cn.com/b4562737671ad2dc646ade25912f5a35e067aec2eec59f106b4b780a1c41bdff-image.png)

考虑维护一个单调递增栈stack，stack中存储对应的索引值，如果h[i] < h[stack.top]，那么对于stack.top来说即遇到了右边界，此时由于stack的单调递增性，那么在stack.top底部的的下一个索引即对应着stack.top的左边界。

```
class Solution:
    def largestRectangleArea(self, heights: [int]) -> int:
        stack = []
        # 单调递增栈
        maxmun = 0
        heights = [0] + heights + [0]    # 添加左右两侧的特殊边界使得只有一个柱子时，也可以形成一个倒V型
        
        for i in range(len(heights)):
            # 对于stack[-1]来说其right_i=i，left_i=stack[-2]
            while len(stack) > 0 and heights[i] < heights[stack[-1]]:
                top = stack.pop()
                s = (i - stack[-1] - 1) * heights[top]
                maxmun = max(s, maxmun)

            stack.append(i)

        return maxmun
```
时间复杂度O(n)，空间复杂度O(n)

另一个经典的单调栈题目为[42.接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)


