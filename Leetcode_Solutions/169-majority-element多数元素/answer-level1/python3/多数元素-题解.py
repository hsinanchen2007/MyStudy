### 解题思路
个人简单思路：
- 遍历数组，使用字典的方式记录每个元素出现的次数，最后找出那个出现次数最多的即可

### 代码

```python3

import collections

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dct = collections.defaultdict(lambda :0)
        for item in nums:
            dct[item] += 1
        
        lgth = len(nums) // 2
        for ky in dct.keys():
            val = dct[ky]
            if val > lgth:
                return ky
```