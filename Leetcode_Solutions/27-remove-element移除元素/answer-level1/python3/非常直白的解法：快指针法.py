
'''
平均用时55ms
执行用时 :36 ms, 在所有 Python3 提交中击败了99.60%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.37%的用户
'''
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        L = len(nums)
        if L == 0:
            return 0
        if L == 1 and nums[0] == val:
            nums.pop()
            return 0
        elif L == 1 and nums[0] != val:
            return 1
        nums.sort()
        cur = 0
        while cur < L and nums[cur] < val:
            cur+=2
        if cur > L:return L
        if cur>0 and nums[cur-1] == val:
            cur-=1
        while cur < len(nums) and nums[cur] == val:
            nums.pop(cur)
            L-=1
        return L     
```
