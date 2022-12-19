执行用时:56ms,在所有Python提交中击败了68.06%的用户；内存消耗:12.5MB,在所有Python提交中击败了36.12%的用户


    def longestConsecutive(self, nums):
        if not nums:return 0
        nums.sort()
        i=0
        j=1
        k=1
        k_max=1
        while j<=len(nums)-1:
            if nums[j]==nums[i]:
                i+=1
                j+=1
            elif nums[j]-nums[i]==1:
                i+=1
                j+=1
                k+=1
            else:
                i=j
                j=i+1
                k=1
            if k>k_max:
                k_max=k
        return k_max