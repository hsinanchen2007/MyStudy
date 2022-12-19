### 解题思路
秘技！反复横跳法

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        # 1. 
        # 找每一列的左侧最大值和右侧最大值时花费O(n), 总时间复杂度O(n^2), 超时!
        # res = 0
        # for i in range(len(height)):
        #     left, right = 0, 0
        #     # 往左找一个最高的柱子
        #     for l in range(i):
        #         if height[l] > left:
        #             left = height[l]
        #     if left <= height[i]:
        #         continue
        #     for r in range(i+1, len(height)):
        #         if height[r] > right:
        #             right = height[r]
        #     if right <= height[i]:
        #         continue
        #     res += min(left, right) - height[i]
        # return res
        
        # 2. 
        # 先遍历两次，保存每个柱子左侧最大值和右侧最大值, 
        # 再最后遍历一次计算每个柱子所接的雨水, O(n),O(n)
        # max_left, max_right = [0] * len(height), [0] * len(height)
        # # 从左向右求每个柱子左侧的最大值
        # l = 0
        # for i in range(1, len(height)):
        #     max_left[i] = max(l, height[i-1])
        #     l = max(l, height[i-1])
        # # 从右向左求每个柱子右侧的最大值
        # r = 0
        # for i in range(len(height)-2, -1, -1):
        #     max_right[i] = max(r, height[i+1])
        #     r = max(r, height[i+1])
        # # 最后遍历一次数组, 求每一列接到的雨水
        # res = 0
        # for i in range(len(height)):
        #     if max_left[i] > height[i] and max_right[i] > height[i]:
        #         res += min(max_left[i], max_right[i]) - height[i]
        # return res
    
        # 3. 
        # 双指针, 左右反复横跳法
        if len(height) < 3:
            return 0
        res, max_left, max_right = 0, height[0], height[-1]
        l, r = 1, len(height)-2
        while l <= r:
            # 不用同时求出左右侧真正的最大值, 反正接到的雨水取决于短板
            max_left = max(max_left, height[l-1])
            max_right = max(max_right, height[r+1])
            if max_left <= max_right:
                if max_left > height[l]:
                    res += (max_left - height[l])
                l += 1
            else:
                if max_right > height[r]:
                    res += (max_right - height[r])
                r -= 1
        return res
        
```