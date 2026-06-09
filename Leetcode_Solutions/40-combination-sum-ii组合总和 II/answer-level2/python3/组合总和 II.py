### 解题思路
回溯算法：如何保证**candidates 中的每个数字在每个组合中只能使用一次**，则设置一个变量begin, 其余的套框架.

### 代码

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def backtrack(path, begin, sums_path, candidates, target):
            if sums_path == target:
                temp = sorted(path)  # 避免重复先排序
                if temp not in result:
                    result.append(temp)
                return
            elif sums_path > target:
                return
            else:
                for i in range(begin, len(candidates)):
                    path.append(candidates[i])
                    sums_path += candidates[i]
                    begin += 1
                    backtrack(path, begin, sums_path, candidates, target)
                    path.pop()
                    sums_path -= candidates[i]

        backtrack([], 0, 0, candidates, target)
        return result
```