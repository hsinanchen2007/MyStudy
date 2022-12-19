### 解题思路
感觉python的很多内置函数，可以很快的解决问题，把握set的特性，没有重复的元素。

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if  len(nums)<2:
            return False
        sets=set(nums)
        if len(sets)==len(nums):
            return False
        return True 
```