**与**[`组合总和Ⅰ题解中解法二`](https://leetcode-cn.com/problems/combination-sum/solution/jie-fa-zong-lan-by-li-xian-sen/)**同样的套路模板**
```python
from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        def backtrack(target, p, start):
            if target == 0:
                output.append(p.copy())
                return
            for i in range(start, len(candidates)):
                if target >= candidates[i]:
                    # 剪枝
                    if i > start and candidates[i - 1] == candidates[i]:
                        continue
                    p.append(candidates[i])
                    # 由于不可重复，故截取 i 之后的数组进行递归操作
                    backtrack(target - candidates[i], p, i + 1)
                    p.pop()

        # 首先对数组排序
        candidates.sort()
        output = []
        backtrack(target, [], 0)
        return output
```
