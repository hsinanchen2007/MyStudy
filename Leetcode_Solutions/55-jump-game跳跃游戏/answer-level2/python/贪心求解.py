### 解题思路
实时更新记录每次当前的能够到达的最远距离，然后判断下标是否超过最远位置，超过返回False, 遍历完变量返回True

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # 找到第一个位置内找到最大的位置, maxIndex + index >= len(nums)
        maxRange = nums[0]
        for index,number in enumerate(nums):
            if index > maxRange:
                return False
            newRange = index + nums[index]
            maxRange = newRange if newRange > maxRange else maxRange

        return True




```