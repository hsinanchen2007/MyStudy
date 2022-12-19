```python
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        # 按列求 比较左面大的和右面大的 判断当前列的顶上有没有水？
        # curLeftMax存储[0..idx - 1] 的最大值 curRightMax存储[idx + 1 ...]的最大值
        # 怎么更新呢
        curLeftMax, curRightMax = 0, 0
        rightMax = [0] * (len(height) + 1)
        for i in range(len(height) - 1, -1, -1):
            rightMax[i] = max(height[i], rightMax[i + 1])
        # print(rightMax)
        count = 0
        for idx in range(len(height)):
            # 这部分用双指针优化？
            if idx > 0:
                curLeftMax = max(height[idx - 1], curLeftMax)
            curRightMax = rightMax[idx + 1]
            if height[idx] < curLeftMax and height[idx] < curRightMax:
                count += min(curLeftMax, curRightMax) - height[idx]
        return count
```