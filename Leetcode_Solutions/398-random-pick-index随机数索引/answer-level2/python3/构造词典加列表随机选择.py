### 解题思路
就是先把索引存到字典对应的列表里面，再随机选择就是了
### 代码

```python3
class Solution:

    def __init__(self, nums):
        self.dict = {}
        for index in range(len(nums)):
            if self.dict.get(nums[index]) is None:
                self.dict[nums[index]] = [index]
            else:
                self.dict[nums[index]].append(index)

    def pick(self, target):
        import random
        return random.choice(self.dict[target])
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
```