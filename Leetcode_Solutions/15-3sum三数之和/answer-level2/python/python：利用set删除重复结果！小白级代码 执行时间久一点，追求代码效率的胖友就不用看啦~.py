小白级代码 执行时间久一点，追求代码效率的胖友就不用看啦~么么哒！
```
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        set_ = set()
        for i in range(len(nums)-2):
            if nums[i] > 0:break
            m,n = i+1,len(nums)-1
            while m<n:
                s=nums[i]+nums[m]+nums[n]
                if s > 0:
                    n = n-1
                if s < 0:
                    m = m+1
                if s == 0:
                    set_.add((nums[i],nums[m],nums[n]))
                    n = n-1
                    m = m+1
        sum_ = []
        for a in set_:
            sum_.append(list(a))
       
        return sum_    
                
```
先附上代码
这段代码清晰在把所有的重复结果都保存起来，存储在set中，即可以删除重复元素，最会运用set转list实现结果