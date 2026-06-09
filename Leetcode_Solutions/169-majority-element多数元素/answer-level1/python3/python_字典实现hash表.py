### 解题思路
1. 用字典建立hash表，key为nums中的元素i，value为nums中i出现的次数
2. 遍历nums，统计所有i出现的次数

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return nums[0]
        dic = dict()
        cnt = len(nums)//2
        for i in nums:
            if i in dic:
                dic[i] += 1
                if dic[i] > cnt:
                    return i
            else:
                dic[i] = 1
```