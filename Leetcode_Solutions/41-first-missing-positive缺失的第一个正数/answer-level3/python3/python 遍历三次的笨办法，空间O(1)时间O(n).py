如果没有负数很容易想到直接对列表内的值取负数即可，然后找到第一个
当存在负数的时候，我的思路是找到一个比最小值还要小的值来做边界即可
然后遍历找到第一个未被改变的数即可
`class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        '''
        我只需要关注 n<len(nums) and n>0 的数
        如果全是正数，那我可以对nums[n]的位置取负数即可以得到结果

        但是存在负数，那我找到数组的下界
        如果当前值大于0
        nums[i] = 下界-N-num[i]-1即可
        如果当前值小于0 大于下届
        nums[i] -= 1

        遍历三次：
        第一次 找下界
        第二次 赋值
        第三次 找到第一个未被改变的数
        '''
        N = len(nums)
        if N==0:
            return 1
        
        # first
        low = nums[0]
        for n in nums:
            low = min(n,low)

        jia_low = min(0,low)
        low = min(0,low)-N
        # second
        for n in nums:
            t = n
            # 反变换
            if t<low:
                t = -t + low - 1

            if t>0 and t<=N:
                if nums[t-1] >= 0:
                # 下界减去1 
                    nums[t-1] = low-nums[t-1]-1
                elif nums[t-1]<0 and nums[t-1]>=jia_low:
                    nums[t-1] = jia_low-1
        # third
        for i,n in enumerate(nums):
            if n>=jia_low:
                return i+1
        return len(nums)+1

`