动态规划：考虑最小情况，依次地推中间情况，最后情况之间的关系，找出状态转移矩阵

(1)定义列表元素的含义，以及结果输出值
   d[i]:列表中到nums[i]为止，最长的上升子序列的长度，包括nums[i]值本身
   结果：应该为列表 d 中的最大值

(2)找状态转移方程
   发现d[i]和d[i-1]没有特别直接的关联
   d[i] = max(d[i],d[j]+1) 更新列表d中每个长度子序列的最大值

(3)定义列表初始值
   每个长度子序列的最小长度均为1，所以列表初始值设置为1

```
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #定义d[i]含义：到nums[i]为止最长的子序列长度
        #d[i] = max(d[i-1],d[j]+1)
        #找出d[]中的最大值
        n = len(nums)
        if not nums : return 0
        if n == 1 : return 1
        d = [1]*n
        for i in range(1,n):
            for j in range(i):
                if nums[i]>nums[j]:
                    d[i] = max(d[i],d[j]+1)  #每次计算最后一个数被应用于序列时，更新当前最大上升子序列的值
        return max(d)
```
