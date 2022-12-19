### 解题思路、
集合判断法

利用Python独有的数据类集合特性。
用nums = list(set(nums))就可以轻松排除了 

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if len(set(nums)) == len(nums):
            return False
        else: 
            return True
        
```