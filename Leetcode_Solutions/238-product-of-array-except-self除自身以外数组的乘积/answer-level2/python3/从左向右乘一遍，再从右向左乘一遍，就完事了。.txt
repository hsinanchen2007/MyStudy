
    def productExceptSelf(self, nums):
        res=[1]*len(nums)
        zuo=1
        for i in range(1,len(nums)):
            res[i]=zuo*nums[i-1]
            zuo=res[i]
        you=nums[-1]
        for i in range(len(nums)-2,-1,-1):
            res[i]=res[i]*you
            you=you*nums[i]
        return res