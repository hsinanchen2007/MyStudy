题目说数字从0到100
第一步，统计数字个数存放在dp，dp[i]表示数字i的个数
第二步，个数累加，累加到最大的那个数就行了，因为后面的都不用求结果；这样一来dp的定义就变了，比如dp[i]就表示数字i和比数字i小的数所有个数，那么如果你要求比5小的数，那就是dp[4]
第三步，特殊情况，dp里面是没有保存比0还小的个数的，同时也不存在比数字0还小的数，所以直接返回0

此方法适用于数组长度较大，但是数值本身取值范围较小的情况

```
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        dp=[0]*101
        for n in nums:
            dp[n]+=1
        for i in range(1,max(nums)):
            dp[i]+=dp[i-1]
        return [0 if n==0 else dp[n-1] for n in nums]
```
