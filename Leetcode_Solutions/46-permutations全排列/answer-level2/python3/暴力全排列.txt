### 解题思路
此处撰写解题思路
暴力全排列
### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        nums=sorted(nums)
        ans=[]
        def solve(l):
            if len(l)==len(nums):
                ans.append(l)
                return 
            for x in nums:
                if x not in l:
                    solve(l+[x])
        solve([])

        return ans
```