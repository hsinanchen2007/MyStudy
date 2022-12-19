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
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates or not target:
            return

        res = []
        candidates.sort()
        candidates = [i for i in candidates if i<=target]
        n = len(candidates)

        def df(path, begin):
            if sorted(path) not in res and sum(path)==target:
                res.append(sorted(path[:]))

            if sum(path) > target:
                    return

            for i in range(begin, n):
                if i > begin and candidates[i] == candidates[i-1]: # 去重。 例如[2,2,2,3], 第二个和第三个2就不要了。
                    continue
                    
                path.append(candidates[i])
                df(path, i+1)
                path.pop()

        df([], 0)

        return res
```

### 类似题目
[39.组合总和](https://leetcode-cn.com/problems/combination-sum/solution/python-hui-su-by-wangziji-2/)
[40. 组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/solution/python-hui-su-by-wangziji-3/)
[46. 全排列](https://leetcode-cn.com/problems/permutations/solution/python-hui-su-by-wangziji/)
[47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/solution/python-hui-su-by-wangziji-6/)
[78. 子集](https://leetcode-cn.com/problems/subsets/solution/python-hui-su-by-wangziji-7/)
[90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/solution/python-hui-su-by-wangziji-8/)