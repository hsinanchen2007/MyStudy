### 解题思路
用的random库

### 代码

```python3
class Solution:

    def __init__(self, nums: [int]):
        self.nums = nums
        self.original = nums
        self.length = len(nums)

    def reset(self) -> [int]:
        """
        Resets the array to its original configuration and return it.
        """
        self.nums = self.original
        return self.nums

    def shuffle(self) -> [int]:
        """
        Returns a random shuffling of the array.
        """
        # 在这直接用set，反正是不重复的
        import random
        return random.sample(self.nums, self.length)
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
```