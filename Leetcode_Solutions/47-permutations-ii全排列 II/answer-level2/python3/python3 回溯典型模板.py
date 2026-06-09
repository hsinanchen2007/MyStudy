### 解题思路
此处撰写解题思路
这个和[面试题 08.08. 有重复字符串的排列组合](https://leetcode-cn.com/problems/permutation-ii-lcci/solution/python-li-yong-pai-xu-qu-zhong-de-hui-su-fa-ji-bai/)一样，先排序，再去回溯，速度会快很多
也可以直接用内置的permutations函数，在hash去重即可。
### 代码

```python3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # return list(set(itertools.permutations(nums)))
        nums.sort()
        ans = []

        def helper(nums,t):
            if not nums:
                ans.append(t)                
                return
            pre = float('inf')
            for i in range(len(nums)):
                if nums[i]!=pre:
                    helper(nums[:i]+nums[i+1:],t+[nums[i]])
                pre = nums[i]
        t=[]
        helper(nums,t)
        return ans

```