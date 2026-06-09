```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        r = []
        nums.sort()
        def backtrack(combination, nums):
            if nums == []:
                r.append(combination)
            temp = float('inf')
            for i in range(len(nums)):
                if nums[i] == temp:
                    continue
                backtrack(combination + [nums[i]], nums[:i] + nums[i+1:])
                temp = nums[i]
        backtrack([], nums)
        return r
```
先把nums排序了，在回溯的时候减支。回溯时将走过的num从nums里面去掉然后再backtrack直到nums里没有值了，每次如果走的num和上一次走的num值相同就不走这次的num分支了——continue。
