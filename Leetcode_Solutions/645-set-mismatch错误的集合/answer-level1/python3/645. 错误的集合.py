
 [1,2,2,4]
# 输出: [2,3]
# 
#
# 注意: 
#
# 
# 给定数组的长度范围是 [2, 10000]。 
# 给定的数组是无序的。 
# 
#
```

class Solution:
    def findErrorNums(self, nums: list) -> list:
       err = sum(nums) - sum(set(nums))
       re = set(range(1,len(nums) +1) - set(nums))
       return [err,re.pop()]
```