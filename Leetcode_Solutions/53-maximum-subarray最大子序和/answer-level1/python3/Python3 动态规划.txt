设计动态规划：
    第一步：建立一个动态规划表用以记录局部最优解，即record=[0] * len(nums)
    第二步：确定第一个最优解， 即record[0] = nums[0]
    第三步：确定当前最优解和之前最优解的关系。说明：当前最优解是指 从之前到当前值的一个连续数组的的最大和，则
            record[i] = max(nums[i], (nums[i]+record[i-1]))
    优化：动态规划表可以只要两个位置， 当要用max_value 来记录遇到的最大值

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        
        """
      
        # 没有采用优化方法
        # 建立一个记录当前拘捕最优的list， 当前最大值是max(当前值，当前值+前面的值)
        record = [0] * len(nums)
        record[0] = nums[0]
        for i in range(1, len(nums)):
            record[i] = max(nums[i], (nums[i]+record[i-1]))
        return max(record)
    
    
        # 采用优化方法
        if len(nums) == 1:
            return nums[0]
        
        record = [nums[0], max(nums[1], nums[0]+nums[1])]
        max_value = max(record)
        
        for i in range(2, len(nums)):
            record[0], record[1] = record[1], max(nums[i], (nums[i]+record[1])) # 这里有一些索引细节上的改变
            if record[1] > max_value:
                max_value = record[1]
        return max_value
        
        

        