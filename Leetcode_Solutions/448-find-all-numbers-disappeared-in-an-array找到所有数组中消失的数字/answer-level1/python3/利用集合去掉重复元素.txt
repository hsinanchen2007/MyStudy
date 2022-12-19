思路：比较简单，利用集合去掉重复元素即可

```
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        arr = []
        nums_set = set(nums)
        for i in range(1,len(nums)+1):
            if i not in nums_set:
                arr.append(i)
        return arr
```
