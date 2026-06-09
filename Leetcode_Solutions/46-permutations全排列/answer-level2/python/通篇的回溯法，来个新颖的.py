逐个元素的插入，时间空间复杂度均能达到90%以上 [当然不保证，因为力扣不稳定]
```python
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 2:  # 如果为1个或两个元素直接返回
            return [nums]
        # 逐个元素的插入法，每次插入新元素到所有旧排列的所有能插入的位置生成新排列
        preres = [[nums[0]]]  # 最开始只有第一个元素
        for i in nums[1:]:
            res = []
            for temp in preres:
                for j in range(len(temp) + 1):  # 从插入到首到插入到尾
                    res.append(temp[:j] + [i] + temp[j:])
            preres = res  # 成为旧排列
        return preres
```
