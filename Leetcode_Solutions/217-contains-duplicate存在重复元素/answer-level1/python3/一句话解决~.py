### 解题思路
有重复的数的话，set()后的长度一定比原先小
### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: list([int])) -> bool:
        return (len(set(nums)) != len(nums))
```