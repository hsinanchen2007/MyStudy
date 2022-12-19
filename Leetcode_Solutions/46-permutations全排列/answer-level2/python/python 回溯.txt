### 解题思路
```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 新的选择列表)
        撤销选择
```

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []

        result_list = []
        n = len(nums)

        def df(nums, tmp_list):

            if len(tmp_list) == n:
                result_list.append(tmp_list[:]) # copy
                return

            for i, c in enumerate(nums):
                tmp_list.append(c) # choose
                df(nums[:i] + nums[i+1:], tmp_list)
                tmp_list.pop()     # remove

        df(nums, [])
        return result_list

```

### 类似题目
[39.组合总和](https://leetcode-cn.com/problems/combination-sum/solution/python-hui-su-by-wangziji-2/)
[40. 组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/solution/python-hui-su-by-wangziji-3/)
[46. 全排列](https://leetcode-cn.com/problems/permutations/solution/python-hui-su-by-wangziji/)
[47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/solution/python-hui-su-by-wangziji-6/)
[78. 子集](https://leetcode-cn.com/problems/subsets/solution/python-hui-su-by-wangziji-7/)
[90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/solution/python-hui-su-by-wangziji-8/)