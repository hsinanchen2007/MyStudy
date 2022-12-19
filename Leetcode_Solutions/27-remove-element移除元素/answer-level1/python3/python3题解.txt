用 i 来表示数组中元素的下标（反向搜索，i逐渐减小），如果遇到 nums[i] == val 时，删去数组中元素（pop）
这样做可以防止从前向后搜索时，删掉元素后，i继续增大导致漏掉和数组越界
class Solution:
    def removeElement(self, nums, val):
        if nums:
            i = len(nums)-1
            while i>=0 :
                if nums[i] == val:
                    nums.pop(i)
                i-=1
        return len(nums)