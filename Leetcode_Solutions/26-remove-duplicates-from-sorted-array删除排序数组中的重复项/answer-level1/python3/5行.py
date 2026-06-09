class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        temp=1//跳过第一个元素,直接从第二个开始,只要修改一个数 temp+1
        for i in range(1,len(nums)):
            if nums[i]!=nums[i-1]:
                nums[temp]=nums[i]
                temp+=1
        return temp
