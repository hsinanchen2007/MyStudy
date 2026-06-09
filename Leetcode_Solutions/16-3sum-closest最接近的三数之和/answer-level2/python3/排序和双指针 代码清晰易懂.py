
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()

        minvalue=10**10
        end=False
        for k in range(len(nums)-2):
            numsk=nums[k]

            i=k+1
            j=len(nums)-1
            while i<j:
                numsi=nums[i]
                numsj=nums[j]
                s=numsi+numsj+numsk
                if abs(s-target)<minvalue:
                    minvalue=abs(s-target)
                    res=[i,j,k]
                if s>target:
                    j-=1
                    while i<j and nums[j]==nums[j+1]:
                        j-=1
                elif s<target:
                    i+=1
                    while i<j and nums[i]==nums[i-1]:
                        i+=1
                else:
                    res=[i,j,k]
                    end=True
                    break
            if end:
                break
        return nums[res[0]]+nums[res[1]]+nums[res[2]]