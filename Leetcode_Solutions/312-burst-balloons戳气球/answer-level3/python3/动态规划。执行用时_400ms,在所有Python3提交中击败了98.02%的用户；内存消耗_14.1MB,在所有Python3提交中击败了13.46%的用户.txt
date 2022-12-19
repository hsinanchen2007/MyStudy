
    def maxCoins(self, nums: List[int]) -> int:
        if not nums:return 0
        
        nums=[1]+nums+[1]
        dp=[[0 for i in range(len(nums))] for j in range(len(nums))]

        n=len(dp[0])-2
        k=2
        while True:
            for i in range(n):
                ks=i
                js=i+k
                res=[]
                for s in range(ks+1,js):
                    resi=nums[ks]*nums[s]*nums[js]+dp[ks][s]+dp[s][js]
                    res.append(resi)
                dp[ks][js]=max(res)
            n=n-1
            k=k+1
            if k==len(dp[0]):
                break

        return dp[0][-1]