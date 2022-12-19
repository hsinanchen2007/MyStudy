二刷时补个题解，比较好理解


```python
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if target == 0:  # 已经完成组合，则剩余需要增加的元素为空
            return [[]]
        elif not candidates or target < min(candidates):
            return []  # 已经没有可组合项或组合项全部大于target，则不可能完成组合
        res = []
        for i in candidates:
            # 剪枝，使用以下过滤器可避免出现排列不同的重复答案且免排序，x>=i和x<=i都行
            for j in self.combinationSum(list(filter(lambda x: x <= i, candidates)), target - i):
                res.append([i] + j)
        return res
```
