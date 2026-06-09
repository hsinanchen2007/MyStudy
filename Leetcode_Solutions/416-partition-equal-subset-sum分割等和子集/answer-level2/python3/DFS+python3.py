两个相等集合，则每个集合和为总和的一半
利用dfs搜索能否得到半和的序列
先排序，从大的值先开始遍历，速度会快一些
有一个样例，最大的值大于半和，把这个情况剪枝一下，就不会超时了
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sums = sum(nums)
        if(sums & 1):return False
        sums >>= 1
        nums = sorted(nums)[::-1]
        if(nums[0]>sums):return False # 最大值大于半和，直接False
        def dfs(i, part):
            if(part == sums):
                return True
            if(part > sums):
                return False
            for j in range(i+1, len(nums)):
                f = dfs(j, part+nums[j])
                if(f):
                    return True
            return False
        for i in range(len(nums)):
            f = dfs(i, nums[i])
            if(f):
                return  True
        return False
```
