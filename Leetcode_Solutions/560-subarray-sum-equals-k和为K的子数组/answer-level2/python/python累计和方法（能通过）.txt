### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sums = [0]
        n = len(nums)
        count_ = 0
        for i in range(n):
            sums.append(sums[-1] + nums[i])
        for i in range(n):
            count_ = count_ + sums[i + 1:].count(sums[i] + k)
        return count_
        # 累计和方法


```