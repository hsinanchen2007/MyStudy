### 解题思路
1428 ms, faster than 33.29% of Python3

注释掉的是一开始写的回溯算法, 在极端case下会超时 比如(1,1,1,....,1,1,100)

之后看题解知道是0-1背包, 
dp[i][j]的含义是前i个数中存在部分数的和恰好等于j的T/F
注意是0/1背包, 所以每个数可以不选, dp[i]代表所以是前i个数中部分数的和
转移方程是or 值得留意. 

状态定义：dp[i][j]表示从数组的 [0, i] 这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j。
状态转移方程：很多时候，状态转移方程思考的角度是“分类讨论”，对于“0-1 背包问题”而言就是“当前考虑到的数字选与不选”。
1、不选择 nums[i]，如果在 [0, i - 1] 这个子区间内已经有一部分元素，使得它们的和为 j ，那么 dp[i][j] = true；

2、选择 nums[i]，如果在 [0, i - 1] 这个子区间内就得找到一部分元素，使得它们的和为 j - nums[i]。

状态转移方程是：

dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]]

所以使用“动态规划”解决问题的思路是“以空间换时间”，“规划”这个词在英文中就是“填表格”的意思，代码执行的过程，也可以称之为“填表格”
定义了转移方程就是做初始化

### 代码

```python3
class Solution:
    def canPartition(self, nums: List[int]) -> bool:        
        # def solve(i, rest):
        #     if rest==0: return True
        #     for j in range(i, l):
        #         if nums[j]<=rest:
        #             if solve(j+1, rest-nums[j]): return True
        #     return False
        
        # total = sum(nums)
        # if total%2==1:
        #     return False
        # half, l = total//2, len(nums)
        # # nums, l = sorted(nums), len(nums)
        # return solve(0, half)
        total = sum(nums)
        if total%2==1:
            return False
        half, l = total//2, len(nums)
        # dp[i][j]的含义是前i个数中存在部分数的和恰好等于j的T/F
        # 注意是0/1背包, 所以每个数可以不选, dp[i]代表所以是前i个数中部分数的和
        dp = [[0]*(half+1) for _ in range(l+1)] # 这里+1是为了有选前0个数和等于0的状态, 因为dp[1][1]要从dp[0][0]得到
        for i in range(l+1): dp[i][0] = 1
        for i in range(1,l+1):
            for j in range(nums[i-1],half+1):
                # dp[i-1][j]代表不选第i个数, dp[i-1][j-nums[i]]代表选第i个数
                dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]]
        return dp[-1][-1]==1
```

从递推方程可以看到dp[i][:]只和dp[i-1][:]相关, 所以可以把空间复杂度降为O(n)
dp[s] means we can find some elements in nums to sum up to s
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:        
        total = sum(nums)
        if total%2==1:
            return False
        half, l = total//2, len(nums)
        dp = [0]*(half+1) # dp[i]就代表存在一些数的和等于i
        dp[0] = 1
        
        for i in range(1,l+1):
            for j in range(half, nums[i-1]-1, -1): # 这里就要从后往前遍历了, 使得dp[j-nums[i-1]]是i-1时刻的而不是i时刻的. 否则如果正序遍历则dp[j-nums[i-1]]其实是i时刻的, 因为dp[j-nums[i-1]比dp[j]先计算, 
                dp[j] = dp[j] or dp[j-nums[i-1]]
        return dp[-1]==1
#               if dp[half]: return True 其实可以提前终止!! 不用把nums中的所有数都遍历完! 快了一倍
#               return False                
```

关于一开始的回溯/dfs, 发现把nums排序之后只要72ms了!
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:        
        def solve(i, rest):
            if rest==0: return True
            for j in range(i, l):
                if rest>=nums[j]:
                    if solve(j+1, rest-nums[j]): return True
            return False
        
        total = sum(nums)
        if total%2==1 or max(nums)>total//2:
            return False
        half, l = total//2, len(nums)
        nums = sorted(nums, reverse=True) #从大到小排序 相当于克服了[1,1,1,1,...,1,100]那个用例, 每次先遍历大的! 即每次使rest减少的更多更快! 不加reverse还是通不过那个case
        return solve(0, half)
```

再优化, 把中间结果缓存下来, 记忆递归 44ms
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:        
        def solve(i, rest):
            if rest==0: return True
            # if rest<=0: return rest==0
            if rest not in memo:
                for j in range(i, l):
                    if rest>=nums[j]:
                        if solve(j+1, rest-nums[j]): 
                            memo[rest] = True
                            return True
                memo[rest] = False
            return memo[rest]
        
        total = sum(nums)
        if total%2==1 or max(nums)>total//2:
            return False
        half, l = total//2, len(nums)
        nums = sorted(nums)
        memo = {}
        return solve(0, half)
```

另外一个思路差不多的, 只不过容量是从0开始
```
        n, half = len(nums), sum(nums)//2
        # early checking impossible cases
        if sum(nums)%2 == 1 or max(nums) > half: 
            return False
        nums.sort(reverse = True)
        memo = {}
        def dfs(curr, i): # curr: current target (accumulative value)
            if curr >= half: # stopping criteria for DFS
                return curr == half        
            # return any(dfs(curr + nums[j], j) for j in range(i+1, n))
            if curr not in memo:
                memo[curr] = any(dfs(curr + nums[j], j) for j in range(i+1, n))
            return memo[curr]
        return not nums or any(dfs(nums[i], i) for i in range(n))
```