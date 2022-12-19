大体思路类似上一题，递归函数输入剩余目标值和待搜索分支起点

边界状态有
1.若剩余值为0，记录该解，返回
2.如搜索起始点超出剩余值，直接返回

在去重需要判断当前选取的分支值在同一层中是否已被选，如果已经被选了则跳过。
换句话说同一层如果出现多个等值的搜索起点，那么在该层只使用第一个搜索起点，其他等值的搜索起点直接跳过。

```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if len(candidates) == 0:
            return []
        if len(candidates) == 1:
            return [[target]] if candidates[0] == target else []
        
        candidates.sort()
        result = []
        cur_comb = []
        
        def dfs(sub_target, start):
            if sub_target == 0:
                result.append(cur_comb[:])
                return
            elif start == len(candidates):
                return
            elif candidates[start] > sub_target:
                return
            for i in range(start, len(candidates)):
                cur_num = candidates[i]
                if cur_num > sub_target:
                    break
                if i > start and candidates[i] == candidates[i-1]:
                    continue 
                cur_comb.append(cur_num)
                dfs(sub_target-cur_num, i+1)
                cur_comb.pop()
            return
        
        dfs(target, 0)
        return result
```
