```
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 时间复杂度
        size=len(nums)
        # 特殊情况
        if size==0:
            return 1
        #对nums排序
        nums.sort()

        flag=1
        for i in range(0,size):
            if nums[i]>=1:
                # 第一个正整数大于1 直接返回1
                # 1.最小正整数在“左边”
                if flag==1 and nums[i]>1:
                    return 1
                # 第一个正整数为1
                # 改变第一个正整数的标识
                flag=0
                
                if i+1<size:
                    # 最小正整数在“中间”
                    if nums[i+1]-nums[i]>=2:
                        return nums[i]+1
                    continue
        # 循环结束仍然没有return
        if nums[-1]>0:
            # 最小正整数在“右边”
            return nums[-1]+1
        return 1
                    
            
                
                
        
            
            
```
