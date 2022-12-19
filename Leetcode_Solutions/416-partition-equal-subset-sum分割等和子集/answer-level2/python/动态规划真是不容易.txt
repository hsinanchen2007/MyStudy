这道题一定要参考：

[相似题目](https://leetcode-cn.com/problems/target-sum/solution/python-dfs-xiang-jie-by-jimmy00745/)

一定要懂得 01背包问题是怎么回事
- 二维数组存储，两层循环
- 一维数组存储，两层循环，内循环中需要从 N ---> 0，因为只关心上一层保存的内容，不知道我说什么就看链接去

[背包问题讲的不错](https://www.kancloud.cn/kancloud/pack/70125)
[背包问题的例子，有图](https://blog.csdn.net/u013445530/article/details/40210587)

```
F(N) 是最终的答案
F[M][N] 是最终的答案
```

然后就套用就行。


```
class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        total = sum(nums)
        if total % 2 == 1:
            return False
        
        target = total/2
        dp = [False]* (target+1)
        dp[0] = True

        for idx in xrange(len(nums)):
            #print("{} {}".format(idx, dp))
            #import pdb;pdb.set_trace()
            for idy in xrange(target, -1, -1):
                if idy >= nums[idx]:
                    dp[idy] = dp[idy] or dp[idy-nums[idx]]
        
        return dp[target]
```