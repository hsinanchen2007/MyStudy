
    def nextPermutation(self, nums: List[int]) -> None:
        for i in range(len(nums)-1,-1,-1):
            if i==0:
                find=False
                break
            numsi=nums[i]
            numsi_qian=nums[i-1]
            if numsi_qian<numsi:
                i_find=i-1
                find=True
                break

        if not find:
            nums=nums[::-1]
        else:
            find=False
            for i in range(i_find+1,len(nums)):
                if nums[i]<nums[i_find]:
                    j_find=i-1
                    find=True
                elif nums[i]==nums[i_find]:
                    j_find=i
                    find=True
            if not find:
                j_find=len(nums)-1

            nums[i_find],nums[j_find]=nums[j_find],nums[i_find]
            nums[i_find+1:]=nums[i_find+1:][::-1]