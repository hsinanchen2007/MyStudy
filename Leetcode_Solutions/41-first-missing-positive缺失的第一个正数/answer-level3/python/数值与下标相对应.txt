磕磕绊绊终于写出来了～请大家指教！
思想：1、不用考虑超过length的或<=0的数据情况，遇到则i+1
        #     2、若该值不在相应数值坐标下，且相应坐标值不重复，则交换至相应坐标，此时i不变，继续判断当前值。
        #     3、若值重复或不需交换则继续遍历，i+1
        #     4、再次遍历数组，若遇到当前数字与下标不对应，则返回该下标应有数值；
        #     5、若该长度下所有数据都有，则返回后续数值。
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #注意空情况
        if not nums:
            return 1
        length = len(nums)
        i = 0
  
        while i < length:
            if nums[i] > length or nums[i] <= 0:
                i += 1
            else:
                if nums[i] != i+1 and nums[nums[i]-1] != nums[i]:
                    temp = nums[i]      
                    nums[i] = nums[temp-1] 
                    nums[temp - 1] = temp
                else:
                    i += 1
        for i in range(length):
            if nums[i] != i+1:
                return i+1
        return length+1

            
            

