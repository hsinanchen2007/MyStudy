方法一：暴力法
先排序，在不断切片，直到遇到只出现一次的数，返回即可
    
    class Solution:
        def singleNumber(self, nums: List[int]) -> int:
            
            nums.sort()
            while len(nums)>1:
                if nums.count(nums[0])==3:
                    nums = nums[3:]
                else:
                    return nums[0]
            return nums[0]
 


方法二:位运算
这个就不多解释了，评论里也有人解释了
    
    class Solution:
        def singleNumber(self, nums: List[int]) -> int:
            x,y = 0,0
            for i in nums:
                x = (i^x) & ~y
                y = (i^y) & ~x
            return x
        
方法三：集合在求和（大神算法、我只是搬运工而已、、、、滑稽）

    class Solution:
        def singleNumber(self, nums: List[int]) -> int:
            return int((3*sum(set(nums))-sum(nums))/2)