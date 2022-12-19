### 解题思路
两重循环，代码好懂，从头开始匹配
感觉还是很冗余，手生了，要解决一下

### 代码******

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l1=len(nums)
        for i in range (l1):
            a=target-nums[i]
            for j in range(i+1,l1):
                if(a==nums[j]):
                    return i,j
```