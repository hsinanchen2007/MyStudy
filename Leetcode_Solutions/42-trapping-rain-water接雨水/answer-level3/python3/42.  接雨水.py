### 解题思路
先找出最高等点，从最左边和最右边向最高的点遍历

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <= 1:
            return 0

        h_max_index = height.index(max(height))    
        area = 0

        tmp1 = height[0]
        for i in range(0, h_max_index):
            if tmp1 < height[i]:
                tmp1 = height[i]
            else:
                area += tmp1 - height[i]
            i += 1
        
        tmp1 = height[-1]

        for j in range(0, len(height) - h_max_index):
            if tmp1 < height[-j-1]:
                tmp1 = height[-j-1]
            else:
                area += tmp1 - height[-j-1]
            j += 1

        return area





```

第二种解题思路，双指针法就是将上边的一个下标 i，变为两个下标 left，right，分别位于输入数组的两端。向中间移动时，边移动边计算。

除此之外，我们使用 maxleft 作为 0...left 的最大值，maxright 作为 right...结尾 的最大值。 (原搬Pumpkin题解，仅供个人记录)


```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        # 边界条件
        if not height: return 0
        n = len(height)

        left,right = 0, n - 1  # 分别位于输入数组的两端
        maxleft,maxright = height[0],height[n - 1]
        ans = 0

        while left <= right:
            maxleft = max(height[left],maxleft)
            maxright = max(height[right],maxright)
            if maxleft < maxright:
                ans += maxleft - height[left]
                left += 1
            else:
                ans += maxright - height[right]
                right -= 1

        return ans

```
