由[回溯算法@powcai](https://leetcode-cn.com/problems/subsets/solution/hui-su-suan-fa-by-powcai-5/)可知，本题与全排列、子集等属于同一类型题目，即回溯算法。解法参考[回溯算法+剪枝@liweiwei1419](https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/)

重点在于如何记录路径和剪枝。

使用栈`path`压入当前值，递归结束后释放，则第一层递归时，`path`值始终为空。每层递归判断`target`值，作为递归出口：等于`0`时将`path`增加到结果中，小于`0`时递归结束。

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []; path = [] # stack
        candidates.sort()
        def dfs(first, target):
            if target == 0: result.append(path[:]); return
            elif target < 0: return

            for i in range(first, len(candidates)):
                path.append(candidates[i])
                dfs(i, target - candidates[i])
                path.pop()
        dfs(0, target)
        return result
```