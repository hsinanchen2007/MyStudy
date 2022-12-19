这道题和组合总和I大体一致，除了每个数字最多取一次。

考虑到数组有重复数字，需要对结果进行去重，当然也可以在深搜的过程中剪枝操作，遇到重复的情况就剪枝不深搜。

对于相邻位置i-1,i是同一个数字的话，因为如果 i-1 和某几个数字之和等于target，那么i和那几个数字之和也是target，所以我们需要判断到底能不能取i。对于真个问题，我将之前存储元素的tmp列表用来存储对应元素的索引index。如果我们遇到相邻i-1， i元素相同时，我们判断索引列表的最后一个索引是不是和i-1相同即可做出剪枝决定。
```py3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()
        def dfs(num, index, idx):
            if num == target:
                ans.append([candidates[j] for j in index])
                return 
            for i in range(idx, len(candidates)):
                if i > 0 and candidates[i] == candidates[i-1]:
                    if len(index) > 0 and index[-1] != i - 1:
                        continue
                    if len(index) == 0:
                        continue
                if candidates[i] + num <= target:
                    index.append(i)
                    dfs(num + candidates[i], index , i + 1)
                    index.pop()
        dfs(0, [], 0)
        ans = list(ans)
        return ans 
```