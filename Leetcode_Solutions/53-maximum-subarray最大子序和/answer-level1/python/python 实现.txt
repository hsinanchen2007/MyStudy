### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if max(nums)<0:
            return max(nums)
        local_max,global_max=0,0
        for x in nums:

            #print "x=",x,'判断前',local_max,",",global_max
            local_max=max(0,local_max+x)#与0比的意思是如果加上当前元素后和小于0，就将当前元素丢弃了 相当于断开了与之后的联系，这种解法参考https://www.bilibili.com/video/BV1Yb411i7dn
            global_max=max(global_max,local_max)
            #print '判断后',local_max,",",global_max

        return global_max

'''
x= -2 判断前 0 , 0 判断后 0 , 0
x= 1 判断前 0 , 0 判断后 1 , 1
x= -3 判断前 1 , 1 判断后 0 , 1
x= 4 判断前 0 , 1 判断后 4 , 4
x= -1 判断前 4 , 4 判断后 3 , 4
x= 2 判断前 3 , 4 判断后 5 , 5
x= 1 判断前 5 , 5 判断后 6 , 6
x= -5 判断前 6 , 6 判断后 1 , 6
x= 4 判断前 1 , 6 判断后 5 , 6
'''
```