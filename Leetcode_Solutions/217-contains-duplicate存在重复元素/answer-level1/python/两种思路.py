小白写的，第一次写题解：
第一种：
用set排序后求和，第一次提交发现忽略了0元素，所以改了一下，把0全换成1.5之类不是整数的元素，之后再求和

```
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums=[1.5 if i==0 else i for i in nums]
        if sum(nums)==sum(set(nums)):
            return 0
        else:
            return 1
```
第二种：
set后直接看长度是不是一样长就行
```
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums)==len(set(nums)):
            return 0
        else:
            return 1
```
后来发现一句话就可以解决

```
return len(nums) != len(set(nums))
```


