### 解题思路
1. O(NN) 方法很好想到，但是往往会超时的

2. 从末尾开始遍历，nexT 温度标记表，下标为温度值。每次求最小从那天Ti开始

### 代码

```python3
'''
class Solution:
    ## O(NN)
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        nsize = len(T)
        if nsize < 1:
            return []
        
        res = [0 for i in range(nsize)]

        for i in range(nsize-1):
            cnt = 0
            for j in range(i+1, nsize):
                cnt += 1
                if T[j] > T[i]:
                    res[i] = cnt 
                    break 
        
        return res
'''
class Solution(object):
    def dailyTemperatures(self, T):
        nxt = [float('inf')] * 102
        ans = [0] * len(T)
        for i in range(len(T) - 1, -1, -1):
            #Use 102 so min(nxt[t]) has a default value
            warmer_index = min(nxt[t] for t in range(T[i]+1, 102))
            if warmer_index < float('inf'):
                ans[i] = warmer_index - i
            nxt[T[i]] = i
        return ans


```

## 再写代码
1. **从nsize-1 开始反向遍历温度数组，根据温度的取值范围<=100**
    - dp = [0-->float("inf") for i in range(102)] ## **记住离远一点，因此不是101**
    - **用dp[T[i]] = i 记录温度为T[i] 是第几天（从0开始）**
    - 若是当前温度为T[j]，找比其高的，**只能在dp[T[j]+1:]中找，且找最小的val（第几天）**
    - 求最小值，因此dp的初始值得由0改为float("inf") 或 30002 
```
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        nsize = len(T)
        if nsize < 1:
            return []
        if nsize == 1:
            return [0]
        
        #dp = [30002 for i in range(30, 102)]
        dp = [30002 for i in range(102)]
        res = [0 for i in range(nsize)] 

        for i in range(nsize-1, -1, -1):
            dp[T[i]] = i
            #nearest_idx = self.findmin(dp, T[i]+1, nsize) ## error 
            #nearest_idx = self.findmin(dp, T[i]+1, 102) ## OK, can instead by this followings 
            #nearest_idx = min(dp[i]  for i in range(T[i]+1, 102))  ## OK
            nearest_idx = min(dp[T[i]+1:102])  ## faster than aboves...
            if nearest_idx != 30002:
                res[i] = nearest_idx - i 

        return res 

    def findmin(self, dp, start, end):
        idx = dp[start]
        for i in range(start, end):
            idx = min(dp[i], idx)
        
        return idx 
```