题目中提到可以假设数组是非空的，并且给定的数组总是存在多数元素，这样就很容易了，代码如下：
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = {}
        for i in set(nums):
            dic[i] = nums.count(i)
        return max(dic,key=dic.get)
```
