如要组成7，那么我们遍历[1,2,5]，

就有（1+组成6）+（2+组成5）+（5+组成2）三类方案来组成7。

那么只需要将组成6的方案数+组成5的方案数+组成2的方案数加起来即可。

因此从组成0开始+1，依次往上动态规划/迭代即可。
```python
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [1]  # 组合成0的方式就1种，即啥都不取
        for i in range(target):
            res = 0
            for j in nums:  # 遍历nums中的j
                if j <= len(dp):
                    # 可以将目标数拆成当前j跟之前目标数-j，因此所有目标数-j的组合方案都算
                    res += dp[-j]
            dp.append(res)
        return dp[-1]
```
