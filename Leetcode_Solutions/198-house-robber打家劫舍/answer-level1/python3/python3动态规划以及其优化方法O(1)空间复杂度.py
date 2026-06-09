### 解题思路
第一次自己写出来动态规划的题， 好开心。而且还成功优化了，虽然是一个一维数组的。
先看不优化的方法：
1.确定数组，dp[i]   :    抢劫1~i个房间的最大钱数
2.确定初始值，  dp[0]  ： nums[0]   只有一个房间 
               dp[1]  ： max(nums[0:2])   两个房间，其中的较大值
3.确定dp方程：  dp[i] = max[dp[i-1], dp[i-2]+nums[i]]   分为两种情况，抢当前房间和不抢当前房间的
4.其他边界条件：很明显数组只有一个/两个元素时，直接返回就行了。 

优化方法：
计算dp[i]，只需要dp[i-1], dp[i-2]，所以只需要保存两个元素就可以，并且每次计算完一个，更新一下就可以。
### 代码
```python3
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
            
        if length <= 2:
            return max(nums)
        dp = []
        dp.append(nums[0])
        dp.append(nums[0] if nums[0] > nums[1] else nums[1])
        for i in range(2, length):
            dp.append(max(dp[i-1], dp[i-2]+nums[i]))
        
        return dp[-1]
```

优化过后的
```
python3
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
            
        if length <= 2:
            return max(nums)
        last = nums[0]
        now = max(nums[0:2])
        for i in range(2, length):
            temp = now
            now = max(now, last+nums[i])
            last = temp
            # 可以简写为：last,now = now, max(now, last+nums[i])
        return now
```

