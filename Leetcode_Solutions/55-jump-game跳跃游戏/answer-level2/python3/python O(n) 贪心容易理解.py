`class Solution:
    def canJump(self, nums: List[int]) -> bool:
        '''
        贪心，我想到达的距离尽可能 远，那么我之前的位置也都可以达到
        '''
        if len(nums)<=1:
            return True
        # 记录我们可以到达的最原位置，和当前位置
        r_max = nums[0]
        l = 0

        # 如果当前位置小于可以最远的位置则++
        while(l<=r_max):
            r_max = max(nums[l]+l,r_max)
            l = l+1
            if r_max>=len(nums)-1:
                return True
        return False`