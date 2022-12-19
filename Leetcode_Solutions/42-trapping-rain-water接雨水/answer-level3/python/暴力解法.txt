### 解题思路
1672 ms, 14.2 MB, %6.23, %5.04，我果然是个暴力小伙。
每列的**左侧最高**和**右侧最高** 决定该列能存多少雨水，然后注意细节就好了。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        water_cnt = 0
        for i in range(1, len(height)-1):  # 第一列与最后一列无法存雨水
            left_height = max(height[0:i])
            right_height = max(height[i:len(height)])
            water_cnt += max(min(left_height, right_height) - height[i], 0)
        return water_cnt

```