### 解题思路
1. 通过引入辅助字典，转化为“打家劫舍”问题
2. 解题思路偷懒不写了

### 代码
```python
# 第一版代码
class Solution(object):
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: 
            return 0  
        from collections import Counter
        counts = Counter(nums)
        pre, cur = 0, 0
        for i in range(1, max(nums) + 1):
            pre, cur = cur, max(cur, pre + counts[i] * i)
        return cur

# 第二版代码
class Solution(object):
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: 
            return 0  

        counts = {}
        max_value = 0
        for num in nums:
            if num > max_value: 
                max_value = num
            if num not in counts:
                counts[num] = 0
            counts[num] += 1

        pre, cur = 0, 0
        for i in range(1, max_value + 1):
            tmp = cur
            if i in counts:
                cur = max(cur, pre + counts[i] * i)
            pre = tmp
        return cur
```