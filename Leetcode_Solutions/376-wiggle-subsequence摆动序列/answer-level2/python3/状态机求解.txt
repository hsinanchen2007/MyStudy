class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums)<2:
            return len(nums)
        state=0
        up=1
        down=-1
        begin=0
        step=1
        c=len(nums)-1
        for i in range(c):
            if state==begin:
                if nums[i]<nums[i+1]:
                    state=up
                    step+=1
                elif nums[i]==nums[i+1]:
                    state=begin
                else:
                    state=down
                    step+=1
            if state==up:
                if nums[i]>nums[i+1]:
                    state=down
                    step+=1
                else:
                    state=up
            if state==down:
                if nums[i]<nums[i+1]:
                    state=up
                    step+=1
                else:
                    state=down
        return step
                