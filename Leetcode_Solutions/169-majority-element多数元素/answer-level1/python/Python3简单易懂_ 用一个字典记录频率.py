### 解题思路
用字典记录每个数值出现的频率.
最后找最大频率的Key返回.

这是实际工作最常用的方法.

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) <= 0: 
            return -1
        d = {}
        for e in nums:
            d[e] = d.get(e, 0) + 1
        max_key = nums[0]
        for k, v in d.items():
            if v > d[max_key]:
                max_key = k
        return max_key
```