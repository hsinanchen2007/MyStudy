全排列问题，temp记录排列中数字出现的序号。我们考虑一种情况，如果序号2，3两个元素是重复数字，我们在排列时可以按照xxx23xxxx的顺序，但xxx32xxxx就是重复的了，因此对于后面这种情况我们需要去重。我们保持重复元素序号正序排列，也就是2，3重复时，我们只要23而不要32。假设我们在遍历到3时，如果2没有放进来的话，那么从0开始遍历就会把2放进来，因此，遍历到3时，我们判断如果2没有放进来，我们就不进行深搜。

如果遍历到当前的元素，并且当前元素和之前的元素是相同的，加入前面相同的元素没有放进temp，那么
```py3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        
        def completePermutation(temp, idx):
            if len(temp) == len(nums):
                ans.append([nums[i] for i in temp])
                return 
            for i in range(len(nums)):
                if (i in temp ) or (i > 0 and nums[i] == nums[i - 1] and i - 1 not in temp):
                    continue
                
                temp.append(i)
                completePermutation(temp, i + 1)
                temp.pop()
        completePermutation([], 0)
        return ans 
```