一个偷懒的方法，list转换成set或者dic时会去掉重复的元素，然后再转换回list
但是有个bug就是需要再排序一下
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        s = set(nums)
        s = list(sorted(s))

        for i in range(len(s)):
            nums[i] = s[i]
        
        return len(s)
```
