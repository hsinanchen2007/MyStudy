解题思路：
1、要遍历所有排列，那么就是需要在每一个位置都尝试所有的数。这个就可以用到回溯算法，一步尝试一个位置
2、每一步尝试完都判断下这个数组序所构成的排列是否是完美排列

解题方法：回溯
1、判断是否已经建立了一个新排列，即进入到最底层。若是，则计数+1
2、在每一层都遍历所有的情况
3、剪枝：判断第`i`个位置与第`index`层是否满足优美排列的条件，若不满足，则跳过，回到2；否则，执行4
4、`index`表示所在层，把第`i`个数与`index`的数交换。
5、递归：`index+1`，表示进入下一层
6、回溯：将刚才`i`与`index`交换的数再换回来

时间复杂度：
递归深度为`len(nums)`层，但每一层需要执行的递归次数却是由该层的固定位置下可能存在的优美排列的数量决定的。
因此，时间复杂度就是`O（k`），`k`为优美排列的数量
![2.png](https://pic.leetcode-cn.com/fda612fa44f2b7fe1f6c1c8e45c1164d64980ece5f0fddc6e0f49dc2ddff5122-2.png)
```
class Solution:
    def countArrangement(self, N):
        # 边界条件判断
        if N == 0:
            return 0
        # 构造数组
        nums = []
        for i in range(1, N+1):
            nums.append(i)
             
        return self.backtracking(nums, 0)

    def backtracking(self, nums, index):
        res = 0
        # 判断是否建立了一个新的排列：
        if index == len(nums):
            res += 1
            return res
        # 遍历第index层的所有可能
        for i in range(index, len(nums)):
            # 剪枝：对于新加入的这个位置不符合的就直接pass
            if nums[i] % (index + 1) > 0 and (index + 1) % nums[i] > 0:
                continue
            # 交换i与index
            nums[i], nums[index] = nums[index], nums[i]
            # 递归
            res += self.backtracking(nums, index+1)
            # 回溯：把index与i交换的数再交换回来
            nums[i], nums[index] = nums[index], nums[i]
        return res
```