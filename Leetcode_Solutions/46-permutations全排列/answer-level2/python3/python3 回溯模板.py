### 解题思路
此处撰写解题思路
全排列的回溯模板，优雅去除选择之后的元素 nums[:i]+nums[i+1:],t+[nums[i]]


### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # return list(itertools.permutations(nums))

        ans = []
        def helper(nums,t):
            if not nums:
                ans.append(t)
                return 
            for i in range(len(nums)):
                helper(nums[:i]+nums[i+1:],t+[nums[i]])
        t=[]
        helper(nums,t)
        return ans
```