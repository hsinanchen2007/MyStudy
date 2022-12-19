### 解题思路
[回溯+剪枝](https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/)

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        for i, num in enumerate(candidates):
            if num > target:
                continue
            elif num == target:
                res.append([num])
            else:
                sub_res = self.combinationSum(candidates[i:], target - num)
                if sub_res:
                    res.extend([[num] + sub for sub in sub_res]) 
        return res
```