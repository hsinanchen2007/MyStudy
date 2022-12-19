# **方法1：利用python3中set的特性（不含重复元素）**
```
class Solution:
    def containsDuplicate(self, nums) -> bool:
        return len(set(nums)) != len(nums)
```

# **方法2：利用字典查找**
```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dict = {}
        for num in nums:
            if dict.get(num) is None:
                dict[num] = 0
            else:
                return True
        return False
```

*第二篇题解啦！！！*

