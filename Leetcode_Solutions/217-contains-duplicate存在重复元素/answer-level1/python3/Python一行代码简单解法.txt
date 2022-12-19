### 解题思路
还是Python大法好啊
注意：为什么会取not,当 set()长度和nums长度相等会会是true，但是题目要求此时是false，所以会有not来取反

### 代码
```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return  not len(set(nums))==len(nums)
```

