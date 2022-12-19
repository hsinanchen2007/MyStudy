```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        #solution 1 
        # 执行用时 :40 ms, 在所有 python3 提交中击败了92.76%的用户
        #内存消耗 :13.9 MB, 在所有 python3 提交中击败了5.37%的用户
        index = 0
        while index < len(nums):
            if nums[index]==val:
                nums.pop(index)
            else:
                index = index+1
        return len(nums)

        #solution 2
        #执行用时 :68 ms, 在所有 python3 提交中击败了13.54%的用户
        #内存消耗 :13.7 MB, 在所有 python3 提交中击败了5.37%的用户
        for i in range(len(nums)-1,-1,-1):
            if nums[i]==val:
                nums.pop(i)
        return len(nums)

            
```
