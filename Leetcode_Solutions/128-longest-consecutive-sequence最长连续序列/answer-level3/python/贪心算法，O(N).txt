### 解题思路
用贪心策略，每次从nums中取一个数字，从这一点尽可能向两端生长，生成一个连续序列, 再得到最大长度
列表nums中每个数字只访问一次，所以算法复杂度是O(N)

### 代码

```python
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1: return len(nums)

        maxL = 0
        dic = dict([(x, True) for x in nums])
        for number in nums:
            if not dic[number]: continue
            left = number
            while dic.get(left-1):
                left -= 1
                dic[left] = False
            right = number
            while dic.get(right+1):
                right += 1
                dic[right] = False
            maxL = max(maxL, right-left + 1)

        return maxL
```

