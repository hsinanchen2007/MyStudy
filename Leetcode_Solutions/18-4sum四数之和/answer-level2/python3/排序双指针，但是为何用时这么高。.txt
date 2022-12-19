执行用时:2808ms,在所有Python3提交中击败了5.10%的用户内存消耗:13.6MB,在所有Python3提交中击败了11.55%的用户

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res=[]
        for i in range(len(nums)-3):
            if nums[i]==nums[i-1] and i!=0:
                continue
            for j in range(i+1,len(nums)-2):
                if nums[j]==nums[j-1] and j!=i+1:
                    continue
                left=j+1
                right=len(nums)-1
                while left<right:
                    s=nums[i]+nums[j]+nums[left]+nums[right]
                    if s==target:
                        res+=[[nums[i],nums[j],nums[left],nums[right]]]
                        while left<right and nums[left]==nums[left+1]:
                            left+=1
                        left+=1
                        while left<right and nums[right]==nums[right-1]:
                            right-=1
                        right-=1
                    elif s<target:
                        while left<right and nums[left]==nums[left+1]:
                            left+=1
                        left+=1
                    else:
                        while left<right and nums[right]==nums[right-1]:
                            right-=1
                        right-=1
        return res