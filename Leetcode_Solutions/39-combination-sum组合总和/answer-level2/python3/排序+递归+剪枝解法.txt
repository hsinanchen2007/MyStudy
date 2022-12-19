### 解题思路
排序+递归回溯+剪枝解法
### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(candidates, index, c_len, stack, target, res):
            if target == 0:
                res.append(stack[:]) # copy拷贝
            elif target > 0:
                for i in range(index, c_len): # 从index开始循环，排序后，后面数比前面的数要大，不重复计算
                    if target - candidates[i] < 0:
                        break
                    stack.append(candidates[i]) # 添加
                    dfs(candidates, i, c_len, stack, target - candidates[i], res) # index改为i，从i开始，逐层递归
                    stack.pop() #回溯

        if not candidates:
            return []

        candidates.sort()
        c_len = len(candidates)
        res = list(list())
        dfs(candidates, 0, c_len, [], target, res)
        return res
        
```