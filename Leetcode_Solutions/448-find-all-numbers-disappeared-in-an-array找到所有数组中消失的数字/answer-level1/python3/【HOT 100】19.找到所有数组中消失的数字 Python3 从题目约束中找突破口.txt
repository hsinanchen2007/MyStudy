
看到这个题暴力一点可以遍历，然后存在字典里面，然后再遍历1到n看谁不在字典里，就是消失的数字。
但是这就用到了额外的空间，能不能不需要额外的空间来做呢？

题目有个关键点，就是这是一个长度为n的数组，里面的数字呢，有都是在[1,n]的范围内的，它们就可以当做是这张表的index（**但是需要-1，因为index从0开始**），然后每次遍历都去对应的index的位置去把那个数+数组长度，然后最后我们遍历数组的index，发现哪个数小于数组长度，说明这里没有被更改过，说明原数组没有这个index的数字，也就是消失的数字（**消失的数字=index+1，因为index是从0开始的**）：

![image.png](https://pic.leetcode-cn.com/c963bf019025e6a691712a55519cc1804bd7bc125c8732af940253d4fab2c2be-image.png)

如上图：index=2，对应数字为index+1=3的地方的值没有被累加过数组长度，说明原数组根本没有3这个元素

那就可以写代码了，注意index的加一减一的问题：

```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        n = len(nums)
        
        for i in nums:
            '''还需要注意：因为这个数组是被修改过的，所以遍历拿到的对应的数值其实是修改过（累加过数组长度的）
            所以在找对应index的时候，需要先将拿到的数值对数组长度取余，获取它原始的数值，不然会out of range'''
            j = i % n
            nums[j-1] += n
            
        res = []
        for i in range(len(nums)):
            if nums[i] <= n:
                res.append(i+1)
                
        return res
```

**时间复杂度O(n)，额外空间复杂度为O(1)**

![image.png](https://pic.leetcode-cn.com/e85b69d6c6422f853319b2fa9e9ba4a02c42762d82b97da386b70ccf56115b63-image.png)
