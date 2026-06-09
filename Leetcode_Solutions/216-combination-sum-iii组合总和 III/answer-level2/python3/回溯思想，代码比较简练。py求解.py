### 解题思路
回溯思想，从1开始，每次往后推，可以画一个树图构思一下。注意回溯的结束条件。这道题不用剪枝，挺友好。

### 代码

```python3
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def backtrack(i, tmp_sum, tmp):
            if tmp_sum == n and len(tmp) == k:
                res.append(tmp)
                return
            if tmp_sum > n or len(tmp) > k:
                return
            for j in range(i, 10):
                backtrack(j+1, tmp_sum + j, tmp + [j])
        res = []
        backtrack(1, 0, [])
        return res


```