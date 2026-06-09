思路1：三重循环，时间复杂度O(n^3)，空间复杂度O(n)
思路2：排序，时间复杂度O(nlogn)，一冲循环—+双指针，时间复杂度O(n^2)，空间复杂度O(n)
注意点：（1）对于不可能的组合情况进行过滤（2）跳过重复的情况（3）输出结果进行排序，时间复杂度O(3log3)=O(1)
```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums)-2):
            if nums[i]>0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left, right = i+1, len(nums)-1
            while left < right:
                sum = nums[i]+nums[left]+nums[right]
                if sum == 0:
                    res.append(sorted([nums[i], nums[left], nums[right]]))
                    left+=1
                    while left+1<right and nums[left] == nums[left-1]:
                        left+=1
                    right-=1
                    while right-1>left and nums[right] == nums[right+1]:
                        right-=1
                elif sum > 0:
                    right-=1
                    while right-1>left and nums[right] == nums[right+1]:
                        right-=1
                else:
                    left+=1
                    while left+1 < right and nums[left] == nums[left-1]:
                        left+=1
        return res
```
