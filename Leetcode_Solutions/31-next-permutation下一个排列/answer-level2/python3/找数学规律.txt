逆序遍历，若有后面的数字大于前面的数字，则有解，把[i:len(nums)]按升序排列，最后把比nums[i-1]大的最小数字与其交换。
举例说明：假设2431，答案是3124
第一步：2431-->遍历到4的时候满足条件（4>2）
        i

第二步：2431-->2134(把431升序排列)

第三步：2134-->3124(把2和后面的数字比，比2大就交换)
```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1,0,-1):
            if nums[i]>nums[i-1]:
                for j in range((len(nums)-i)//2):
                    nums[i+j],nums[len(nums)-1-j]=nums[len(nums)-1-j],nums[i+j]
                for t in range(i,len(nums)):
                    if nums[t]>nums[i-1]:
                        nums[t],nums[i-1]=nums[i-1],nums[t]
                        return
        nums.reverse()
```
