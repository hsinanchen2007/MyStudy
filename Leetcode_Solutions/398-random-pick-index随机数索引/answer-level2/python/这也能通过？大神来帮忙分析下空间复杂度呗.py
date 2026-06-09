```
class Solution(object):
    import random
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.num_index_dict = {}
        for i, num in enumerate(nums):
            if num not in self.num_index_dict:
                self.num_index_dict[num] = [i]
            else:
                self.num_index_dict[num].append(i)

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        index = random.randint(0, len(self.num_index_dict[target]) - 1)
        return self.num_index_dict[target][index]
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
```

每个索引的值都被存储了，那空间复杂度不是O(N)么？