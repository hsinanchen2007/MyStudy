### 解题思路
以前看过解题思路，只记得这种双指针解法，不确定是不是完全复刻了那个解法。大家如果需要图解的话，需要自己翻翻别人的解题。

**本题关键思路**：List中任意一个点（用current_idx来指代）能不能接雨水，取决于current_idx左边所有柱子的left_max和右边所有柱子的right_max的min是否高于current_idx的柱子。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        # 题目只说了n个非负整数，所以len(height)应该可以是1或2。这种情况下，不可能有雨水，所以特殊情况先写为敬。
        if len(height) <= 2:
            return 0
        # 普通情况，给这个List一个左指针和一个右指针，默认先从左边指针的数开始考察，所以给了一个“现指针”，index跟左指针相等。
        current_idx, left_idx, right_idx = 0, 0, len(height) - 1
        left_max = 0
        right_max = 0
        rain = 0
        # 左右指针向中间慢慢收缩，直到他们俩重合就结束了
        while left_idx < right_idx:
            # 计算左右当前左右柱子最大值
            left_max = max(left_max, height[left_idx])
            right_max = max(right_max, height[right_idx])
            # 他们的min就是最短那根的高度，只要比这个高度高，就能接雨水，否则就pass
            short = min(left_max, right_max)
            if height[current_idx] >= short:
                pass
            else:
                rain += short - height[current_idx]
            # tricky的地方在这，所谓的现指针，就是左右指针互相跳来跳去
            # 若当前左指针的柱子比右指针的短，我们就把左指针往右移一格，然后把现指针指向左指针
            # 若当前右指针的柱子大于等于左指针的柱子，我们就把右指针往左移一格，现指针指向右指针
            # 这么做的目的，其实就是要把第1格到倒数第二格的所有格子都遍历且仅遍历一遍
            if height[left_idx] < height[right_idx]:
                left_idx += 1
                current_idx = left_idx
            else:
                right_idx -= 1
                current_idx = right_idx
        return rain
            
            


```