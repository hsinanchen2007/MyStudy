### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        # 边界
        if len(nums) < 3:
            return False

        # 初始化
        win = [max(nums), max(nums)]

        # 主逻辑
        for i in range(len(nums)):
            if nums[i] < win[0]:
                win[0] = nums[i]
            else:
                if nums[i] > win[0] and nums[i] < win[1]:
                    win[1] = nums[i]
                else:
                    if nums[i] > win[1]:
                        return True

        return False

```