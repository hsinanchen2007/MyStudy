
```
def rob(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    n=len(nums)
    if n==0:
        return 0
    if n==1:
        return nums[0]
    dp=[0]*n
    dp[0]=nums[0]
    dp[1]=max(nums[0],nums[1])
    for i in range(2,n):
        dp[i]=max(dp[i-1],dp[i-2]+nums[i])
    return dp[-1]
```
状态转移方程为dp[i]=max(dp[i-1],dp[i-2]+nums[i])
注意有状态方程写程序的步骤思路
dp[i]表示到底i个元素(下标为0，对应list)时，所要的结果。
所以dp[0]=nums[0] ,dp[1]=max(nums[0],nums[1])

动态规划基本要素：①后面由前面决定，层层递推
②后面的不影响前面的
