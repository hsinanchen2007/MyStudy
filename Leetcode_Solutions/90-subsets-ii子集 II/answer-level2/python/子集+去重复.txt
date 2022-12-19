### 解题思路
先对数组进行排序，然后使用深度优先搜索查找子集，如果子集出现过了，则去掉重复。
这个想法最主要是先排序，这样可以使得列表list中的相同值出现的顺序。

### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        return self.dfs(nums, ans, [], 0)

    def dfs(self, nums, ans, subset, idx):
        if subset not in ans:
            ans.append(subset)
        for i in range(idx, len(nums)):
            self.dfs(nums, ans, subset+[nums[i]], i+1)
        return ans
```