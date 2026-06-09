### 解题思路
相似习题:
[46. 全排列](https://leetcode-cn.com/problems/permutations/)
[面试题38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)
[面试题 08.08. 有重复字符串的排列组合](https://leetcode-cn.com/problems/permutation-ii-lcci/)
[面试题 08.07. 无重复字符串的排列组合](https://leetcode-cn.com/problems/permutation-i-lcci/)



### 代码

```python3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(tmp):
            if len(tmp) == len(nums):
                res.append(tmp)
                return
            for i in range(len(nums)):
                if i>0 and nums[i] == nums[i-1] and not visited[i-1]:
                    continue
                elif not visited[i]:
                    visited[i] = True
                    dfs(tmp+[nums[i]])
                    visited[i] = False
        
        nums.sort()
        res = []
        visited = [False]*len(nums)
        dfs([])
        return res
```