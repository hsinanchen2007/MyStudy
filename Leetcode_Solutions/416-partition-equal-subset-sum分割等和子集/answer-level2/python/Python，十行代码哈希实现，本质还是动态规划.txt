
```python
    # 主要思想为：记录对nums取所有组合下可能出现的和，最后判断总和的一半是否在这些和中，其实还是动态规划
    # 以下实现进行了提前结束，迭代时的哈希判断等优化
    def canPartition(self, nums: List[int]) -> bool:
        target, remain = divmod(sum(nums), 2)
        if remain:  # 如果不能整除直接返回
            return False
        ans = {0}
        for i in nums:
            for j in list(ans): # 循环中会改变ans
                j += i
                if j == target:  # 提前结束
                    return True
                ans.add(j)  # 之前的结果加当前数能得到的结果
        return False
```