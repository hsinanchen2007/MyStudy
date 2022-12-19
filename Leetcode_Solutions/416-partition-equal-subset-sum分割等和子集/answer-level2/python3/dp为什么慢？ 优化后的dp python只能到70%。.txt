这个dp用了将近572ms
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        nums.sort(reverse=True) # 从大往小搜更快
        halfsum = sum(nums) >> 1
        if sum(nums) != halfsum << 1: return False

        dp = [False for _ in range(halfsum+1)]
        dp[0] = True

        for n in nums:
            for s in range(halfsum, 0, -1):
                if s-n >= 0:
                    dp[s] = dp[s-n] or dp[s]
                else:
                    break   # s < n, break
            if dp[-1]: break
        return dp[-1]
```


而这个第一名的代码只用了32ms,差了十倍多
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        def helper(nums,target,index):
            if target==0:
                return True
            if index>=len(nums) or target<0:
                return False
            if(helper(nums,target-nums[index],index+1)):
                return True
            j=index+1;
            while j<len(nums) and nums[index]==nums[j]:
                j=j+1
            return helper(nums,target,j)

        s= sum(nums)
        if s%2!=0:
            return False
        target=s/2
        return helper(nums,target,0)
```

发现当数组值很稀疏的时候(比如nums=[100]*100),
dp有很多值是False，每次从0到halfsum的循环显得多余(每一个dp内循环每次需要从0到5000)
于是用将dp值为True的塞到set里，每次循环set中的值，减少了很多计算量，时间降到了160ms
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        nums.sort(reverse=True)
        halfsum = sum(nums) >> 1
        if sum(nums) != halfsum << 1: return False
        if nums[0] > halfsum: return False

        dp = set((0,))
        for n in nums:
            for s in list(dp):
                if n + s < halfsum: dp.add(n+s)
                elif n + s == halfsum: return True
        return False
```
