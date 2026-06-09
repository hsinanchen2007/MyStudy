### 解题思路
设置一个字典，当第一次出现的时候将其赋值为1，再次出现加一，再循环中判断是否大于一半，返回结果

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numbers={}
        n = len(nums)
        for i in nums:
            if i in numbers:
                numbers[i]+=1
            else:
                numbers[i] =1
            if numbers[i] > (n//2):
                return i
        return 0
```