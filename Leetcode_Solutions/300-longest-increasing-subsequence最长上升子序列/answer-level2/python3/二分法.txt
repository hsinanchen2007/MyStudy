

```

class Solution:
    '''
    维护一个上升数组LIS，遍历nums,当出现的数大于这个数组直接append，否则替换掉数组中大于这个数的最小值
    最后LIS的长度就是最长上升子序列的长度
    '''
    def lengthOfLIS(self, nums: List[int]) -> int:
        LIS = []
        #遍历num
        for i in range(len(nums)):
            #当LIS为空，直接append nums[i]
            if not LIS:
                LIS.append(nums[i])
            #如果nums[i]大于LIS中的所有数（因为LIS为顺序递增，只需要大于LIS[-1]），说明比前一个数大，可以继续加进LIS
            elif nums[i] > LIS[-1]:
                LIS.append(nums[i])
            #如果nums[i]小于等于LIS中的某个数，用nums[i]替换LIS中大于nums[i]中最小的数
            else:
                LIS = self.insert(LIS,nums[i],0,len(LIS)-1)
        return len(LIS)
    
    #用二分查找的方法查找最小的大于nums[i]的数
    def insert(self,nums,num,left,right):
        while left <= right:
            mid = left+(right-left)//2
            if left == right:
                nums[left] = num
                break
            elif left < right and num <= nums[mid]:
                right = mid
            elif left < right and num > nums[mid]:
                left = mid+1
        return nums



```