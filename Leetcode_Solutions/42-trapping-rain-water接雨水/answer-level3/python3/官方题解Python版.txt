[CSDN链接](https://editor.csdn.net/md/?articleId=105312153)
方法一：暴力（超时）
```
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        size = len(height)
        for i in range(size):
            max_left = 0
            max_right = 0
            for j in range(i, -1, -1):
                max_left = max(max_left, height[j])
            for k in range(i, size):
                max_right = max(max_right, height[k])
            ans += min(max_left, max_right)- height[i]
        return ans
```
方法二：动态规划```
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        ans = 0
        size = len(height)
        left_max = [0 for i in range(size)]
        right_max = [0 for i in range(size)]
        for i in range(size):
            left_max[i] = max(height[i], left_max[i-1])
        right_max[size - 1] = height[size - 1]
        for i in range(size-2, -1, -1):
            right_max[i] = max(height[i], right_max[i+1])
        for i in range(size-1):
            ans += min(left_max[i], right_max[i]) - height[i]
        return ans
```
方法三：双指针
```
class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        left_max = right_max = 0
        ans = 0
        while left <= right:
            if left_max < right_max:
                ans += max(0, left_max - height[left])
                left_max = max(left_max, height[left])
                left += 1
            else:
                ans += max(0, right_max - height[right])
                right_max = max(right_max, height[right])
                right -= 1
        return ans
```
