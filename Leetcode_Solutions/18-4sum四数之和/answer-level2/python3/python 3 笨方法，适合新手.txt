class Solution:
    def fourSum(self, nums, target):
        nums.sort()                     #对原数组进行排序
        last_,n=[],len(nums)            #建立空列表
        for i in range(n-3):            #依次循环 取第一个点：
            target-=nums[i]             #目标值-第一个点的值
            for j in range(i+1,n-2):    #依次循环取第二个点：
                target-=nums[j]         #目标值-第二个点的值
                pp={}              
                for index,num in enumerate(nums[j+1:],j+1):
                    if target-num in pp:   #如果仍能找到两个点，满足条件，记录
                        if [nums[i],nums[j],target-num,num] not in last_:
                            last_.append([nums[i],nums[j],target-num,num])
                    pp[num]=index
                target+=nums[j]          #反向加回减掉的值
            target+=nums[i]              #反向加回减掉的值
        return last_                     #输出
                    
        