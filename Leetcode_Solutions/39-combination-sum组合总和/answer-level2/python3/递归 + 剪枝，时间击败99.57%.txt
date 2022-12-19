![image.png](https://pic.leetcode-cn.com/08d65ee97a01f85f460ef666f19e797a718773733cac9d6253c6890b31facdcb-image.png)

凑巧的话还能击败100%
![image.png](https://pic.leetcode-cn.com/067d6c846712014bd2b450268dc79dfd0bcc25d1c7892d27c436e28d3fc53c31-image.png)


利用递归+剪枝方法实现效率最大化，希望可以讲清楚~

方法通过以下几个步骤：
1. 将 candidates 按照大小排序，方便接下来剪枝
2. 判断 candidates[i]*2 是否小于target，如果不小于则说明只剩下一种情况 即 candidates[i] == target
3. 如果 candidates[i]*2 小于target，则说明 target - candidates[i] > candidates[i]，此时存在多种搭配可能，只需将target - candidates[i]这个值作为新的target，查看candidates[i: ]中的所有搭配可能 （此时比candidates[i]还要小的数的搭配组合已经计算过，无需重复计算，因此新的candidates vector从第i个开始），并将这些可能与candidates[i]结合起来，即最终结果。

```python []
def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates: return []
        res = []
        candidates.sort()
        for i in range(len(candidates)):
            if candidates[i] * 2 <= target:
                b = self.combinationSum(candidates[i: ], target - candidates[i])
                for c in b:
                    c.insert(0, candidates[i])
                    res.append(c)
            elif candidates[i] == target and [candidates[i]] not in res:
                res.append([candidates[i]])
        return res
```
