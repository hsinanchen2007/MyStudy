拿到这道题的时候，一想卧槽好简单啊，反手就是一个暴力……
```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        return self.helper(nums, 0, 0, 0)

    def helper(self, nums, idx, branch1_sum, branch2_sum):
        if idx == len(nums):
            return branch1_sum == branch2_sum
        
        res1 = self.helper(nums, idx + 1, branch1_sum + nums[idx], branch2_sum)
        res2 = self.helper(nums, idx + 1, branch1_sum, branch2_sum + nums[idx])

        return res1 or res2
```
果不其然，超时了，哈哈哈哈。。

而且这种暴力解法无法使用记忆化搜索，想着怎么用记忆化搜索取解决。。
题目要求全部数字分成两部分，两部分的和要相等，这不就是说两部分的和要等于整体数组的和的一半吗？那么问题就转换成了能否用这么多个数字（可以只取部分数字）取成一个和为**数组总和的一半(sum)**的子数组。用一些数去填充某个空间，是不是很熟悉，背包问题呀！背包空间是sum/2！所以将暴力递归转换为记忆化搜索：
```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        _sum = sum(nums)

        if _sum % 2 != 0:
            return False  # 不能被平分，一定是False

        bag_volume = _sum // 2  # 背包容量

        # 背包容量从0到bag_valume，记忆矩阵初始化值为-1
        # self.record[i][j]如果等于1，表明用前i+1个元素能够填充容量为j的背包
        # self.redocr[i][j]如果等于0，表明用前i+1个元素不能填充容量为j的背包
        self.record = [[-1] * (bag_volume + 1) for _ in range(len(nums))]
        return self.helper(nums, bag_volume, len(nums) - 1)

    def helper(self, nums, c, idx):
        """
        考察索引为的元素，以及它前面的数字，能否填充容量为c的背包。
        :param nums: 原数组
        :param c: 背包容量
        :param start_idx: 考察的id
        :return: 能否被填充的结果——能(True)，不能(False)
        """
        if idx < 0:  
            return False
        
        if c == 0:  # 条件满足
            return True

        if self.record[idx][c] != -1:
            return bool(self.record[idx][c])  # 直接返回记忆的结果

        # 这个元素我不要，我考察前面的元素能否填充这个背包
        res = self.helper(nums, c, idx - 1)
        if c >= nums[idx]:
            # 这个元素我要了，前提是你的背包容量要能容纳下这个元素，然后继续去考察前面的元素能否填充加了这个元素之后的背包
            # 两个条件满足一个就可以了，所以是或运算
            res = res or self.helper(nums, c - nums[idx], idx - 1)

        self.record[idx][c] = bool(res) # 记忆

        return res
```
通过啦，但是我们还可以用dp来解决背包问题，思路和自顶向下的记忆化搜索策略差不多，代码更简单一些
```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        _sum = sum(nums)

        if _sum % 2 != 0:
            return False

        bag_volume = _sum // 2
        # dp[i]的意义——————用索引从 0到i这i+1个数字能否填充容量为i的背包
        dp = [-1] * (bag_volume + 1)  # 一维dp，通过滚动数组来优化

        # 边界条件，考察第一个元素作为dp数组的初始化
        for i in range(bag_volume + 1):
            dp[i] = (nums[0] == i)

        # 从第2个元素开始
        for i in range(1, len(nums)):
            for j in range(bag_volume, -1, -1):
                if j < nums[i]:
                    break  # 提前结束的一个优化
                dp[j] = dp[j] or dp[j - nums[i]]

        return dp[-1]  # 最后返回dp[-1]，代表用这len(nums)个元素能否填充容量为bag_volume的背包。
```