class Solution:
    def maxSubArray(self, nums):
        n_nums = len(nums)
        if n_nums <= 1: # 一个数的数组，返回当前元素
            return nums[0]
        i = 0
        max_val = nums[0]
        while i < n_nums: 
            if nums[i] <= 0:
                max_val = max(max_val, nums[i])
                i += 1
            else:
                break
        if i == n_nums:  # 如果全部是负数，则返回最大一个 O(n)
            return max_val
        
        # 去除尾部的负数
        new_beg = i
        j = n_nums - 1
        while j >= 0:
            if nums[j] <= 0:
                j -= 1
            else:
                break
        new_end = j
        
        # new_beg/new_end 是过滤掉开头和结尾负数后的结果，整个复杂度不超过O(n)
        skip_flag = False #  跳过中间负数
        k = new_beg +1    # 新索引起点，第一个数肯定是非负整数
        max_sum, tmp_sum = nums[new_beg], nums[new_beg]  # max_sum和tmp_sum 分别是 最大和、部分和  
    
        while k <= new_end: 
            if nums[k] >= 0: # 非负数
                if not skip_flag:
                    tmp_sum += nums[k] # 连续子序列，求和 
                    max_sum = max(tmp_sum, max_sum) # 取最大值
                else: # 非连续子序列，中间隔断，tmp_sum重新还是计算
                    tmp_sum = nums[k]
                    max_sum = max(max_sum, tmp_sum)
                    skip_flag = False
            elif nums[k] < 0: # 负数
                if tmp_sum + nums[k] < 0: # 负数导致当前部分和小于0，跳过负数重新开始统计部分和
                    skip_flag = True # 部分和重计标识
                    max_sum = max(max_sum, tmp_sum) # 更新最大和
                    tmp_sum = 0 # 部分和清0
                else:
                    tmp_sum = tmp_sum + nums[k] # 累计部分和
            k += 1
        return max(max_sum, tmp_sum) # 返回最大和
        