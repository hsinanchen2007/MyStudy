### 解题思路
两种方法, 一种是dfs搜索
对于当前和cur 与 当前元素nums[i-1], 要么有cur+nums[i-1], 或 cur-nums[i-1]
如果最后cur==S, 则这一条路径符合要求, 返回1

### 代码

```python3
    if (sum(nums)+S)%2==1: return 0        
    l = len(nums)
    d = {}
    def dfs(cur, i): # cur 当前和, i当前遍历index
        if i<l and (cur, i) not in d:
            d[(cur, i)] = dfs(cur+nums[i], i+1) + dfs(cur-nums[i], i+1)
        return d.get((cur, i), int(cur==S))
    return dfs(0, 0)
```

对于动态规划, 这题和1049最开始的思路很像, 因为最后的结果是所有num加减的结果
即可以将nums分为两组数A,B 使得A-B=S. 又有A+B=sum(nums)
所以可得 2A = (S+sum(nums)), 即变成了一个0-1背包问题, 即从nums挑元素使得和为S
注意这里不是求最值而是求方案, 所以dp[i][j]定义为前i个元素的和为j的方案数
状态转移为
```
dp[i][j] = dp[i-1][j] # 不选i
if nums[i-1]<=j:
    dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j] # 选i
```

但是二维数组对于case [0,0,0,0,0,0,0,0,1] 1 通不过, 结果为1但正确答案为256

```
    s = sum(nums)        
    if (s+S)%2==1: return 0 
    target = (s+S)//2
    l = len(nums)
    dp = [[0]*(target+1) for _ in range(l+1)]
    for i in range(l+1): dp[i][0] = 1 #因为转化为0-1背包可以不选所以dp[i][0]=1, 即所有都不选
    for i in range(1, l+1):
        for j in range(1, target+1):
            dp[i][j] = dp[i-1][j]
            if nums[i-1]<=j: # 代表和到j的方案数, 即选i时就是到j-nums[i]的方案数加上不选i的方案数
                dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j] 
    return dp[-1][-1]
```
简化到O(n)复杂度, 去掉[i-1]维, 要倒序遍历
```
    s = sum(nums)        
    if (s+S)%2==1 or s<S: return 0  # 不加第二个条件会超内存, 因为这种case [1,2,7,9,981] 1000000000
    target = (s+S)//2
    l = len(nums)
    dp = [0]*(target+1) # 因为是0-1背包可以不选所以dp[0]=1
    dp[0] = 1
    for i in range(1, l+1):
        for j in range(target, nums[i-1]-1, -1):
            dp[j] = dp[j-nums[i-1]]+dp[j]
    return dp[-1]
```