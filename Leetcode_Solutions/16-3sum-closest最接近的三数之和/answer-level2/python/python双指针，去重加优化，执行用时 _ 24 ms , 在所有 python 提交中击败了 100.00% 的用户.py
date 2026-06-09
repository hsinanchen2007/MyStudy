# 思路
- 先对数组排序
- 进行遍历数组 nums ，每遍历一个值利用其下标k，形成一个固定值 nums[k]，使用两个指针， 左边起点为 left = k + 1 ，右边终点 right = nums.length - 1 
- 因为数组已经排序，故在 [left, right]区间内，最大值 sum_three_max = nums[k] + nums[right] + nums[right - 1],最小值为 sum_three_min = nums[k] + nums[left] + nums[left + 1];
    如果最大值sum_three_max比target还小，或者最小值sum_three_min比target还大，这一轮就可以跳过了。
    否则就按照正常的双指针找法。
- 根据 sum = nums[left] + nums[right] + nums[k] 的结果，判断 sum 与目标 target 的距离，如果更近则更新结果 min_sum，同时判断 sum 与 target 的大小关系，因为数组已经排过序，如果 sum > target 则 right--，如果 sum < target 则 right++，如果 sum == target 直接返回结果


```
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        len_num=len(nums)
        if len_num==3:
            return nums[0]+nums[1]+nums[2]
        nums=sorted(nums)
        min_sum=nums[0]+nums[1]+nums[2]
        for ix in range(0,len_num-2):
            left,right=ix+1,len_num-1
            sum_three_max= nums[right]+nums[right-1]+nums[ix]
            sum_three_min=nums[left]+nums[left+1]+nums[ix]
#             如果最大值都比target小，这一轮就不用了
            if sum_three_max<target:
                if abs( sum_three_max-target)<abs(min_sum-target):
                    min_sum=sum_three_max
                continue
#             如果最小值都比target大，这一轮就不用了
            elif sum_three_min>target:
                if abs(sum_three_min-target)<abs(min_sum-target):
                    min_sum=sum_three_min
                continue
            else:
                #和之前的三数和类似，用left和right指针进行遍历
                while(right>left):
                    sum_three=nums[ix]+nums[left]+nums[right]
                    if abs(sum_three-target)<abs(min_sum-target):
                        min_sum=sum_three
                    if sum_three <target:
                        left+=1
                        #去重，提高效率
                        while left<right  and nums[left-1]==nums[left]:left+=1
                    elif sum_three >target:
                        right-=1
                        #去重，提高效率
                        while left<right  and nums[right+1]==nums[right]:right-=1
                    else :
                        return sum_three
        return min_sum
```
