### 解题思路
**方法一、动态规划**
dp[i]中存储的是当目标和为I时的所有情况
dp[i] = x for x in dp[i-c] + [c] for c in candidates

### 代码
```python
class Solution(object):
    def combinationSum(self, candidates, target):
        dp = [[] for _ in range(target+1)]
        #数组元素包括目标和均为正整数
        for i in range(1,target+1):
            for c in candidates:
                if i - c < 0:continue
                else:
                    if not dp[i-c]:
                        if i == c:
                            dp[i].append([c]) 
                    else:
                        for m in dp[i-c]:
                            dp[i].append([c] + m)
        #去重
        for i in range(len(dp[-1])):
            dp[-1][i].sort()
        ans = list(set(map(tuple,dp[-1])))
        for i in range(len(ans)):
            ans[i] = list(ans[i])
        return ans
```
### 解题思路
**方法二、回溯算法**
target[x] = c + all(target[x-c])

### 代码
```python
class Solution:
    def combinationSum(self, candidates,target):
        self.ans = []
        temp = []
        self.sumtotal(candidates,target,temp,0)
        return self.ans

    def sumtotal(self,candidates,target,temp,start):
        #终止条件
        if target == 0:
            self.ans.append(temp[:])
        #start的加入是为了防止重复组合的出现，访问过的元素就不再访问
        for i in range(start,len(candidates)):
            res = target - candidates[i] 
            if res < 0:continue
            temp.append(candidates[i])
            self.sumtotal(candidates,res,temp,i)
            temp.pop()
```

