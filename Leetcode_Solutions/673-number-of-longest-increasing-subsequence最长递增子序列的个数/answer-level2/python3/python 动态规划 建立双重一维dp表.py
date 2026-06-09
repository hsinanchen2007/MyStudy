> 解题思路
> 1. 以终为始：最长递增子序列的个数记为res，建立双重dp表，参考求最长递增子序列的方法length[i]表示对应nums[i]的子序列长度，count[i]表示对应nums[i]的子序列长度的个数
> 2. 数学归纳法，假设 dp[0...i-1] 都已知，想办法求出 dp[i]，找length(i), length(j), count[i], count[j]的变化关系。基于初始化的值，正常都是length前面的值小于等于length后面的值（初始化为1），即这个长度的递增子序列第一次出现。
> ![在这里插入图片描述](https://pic.leetcode-cn.com/72db393b6cede0a7df45d790766c71ff2d6e9449dc43e420db963ab638482cda.png)
> 如果这个i前面有两个相同的值，第二次进入这个条件时，这个i已经是做过length[i] = length[j] + 1，即有两个长度相同的子序列
> ![在这里插入图片描述](https://pic.leetcode-cn.com/0200f14b39b44018e04ba957b08bc35a3a757170e8c04087de03a10afdcb7f47.png)
> 3. 上面求出来的count[i]只是以nums[i]结尾的最长子序列个数，要求最长递增子序列个数还要遍历找最长递增子序列（可能有多个），求count的和


```
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        # 初始化dp表，这题数学归纳的关键在于基于初始化的值，怎么记录长度相同的子序列长度
        # 建立一个双重一维dp
        count = [1 for i in range(len(nums))]     # 以x结尾的最长子序列个数
        length = [1 for i in range(len(nums))]    # 以x结尾的最长子序列长度
        res = 0

        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:      
                    # 在初始化的length表基础上，正常都是length前面的值小于等于length后面的值（初始化为1）           
                    if length[j] >= length[i]:
                        length[i] = length[j] + 1                       
                        count[i] = count[j]
                    # 如果这个i前面有两个相同的值，第二次进入这个条件时，这个i已经是做过length[i] = length[j] + 1，即有两个长度相同的子序列
                    elif length[j]+1 == length[i]:
                        count[i] += count[j]
        
        maxSub = max(length)
        # 是找最长递增子序列，要在length中找长度最长子序列的个数之和
        for i in range(len(nums)):
            if length[i] == maxSub:
                res += count[i]

        return res
```
