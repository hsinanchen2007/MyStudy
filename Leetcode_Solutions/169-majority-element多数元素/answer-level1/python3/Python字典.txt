### 解题思路
利用字典统计出现次数。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        dic = {}
        for i in range(n):
            dic[nums[i]] = dic.get(nums[i],0) + 1
            if dic[nums[i]] > n/2:
                return nums[i]
```