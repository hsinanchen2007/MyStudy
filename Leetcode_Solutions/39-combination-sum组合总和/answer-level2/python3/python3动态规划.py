### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates or not target:
            return []
        dp=[[] for _ in range(target+1)]
#初始化dp
        for i in candidates:
            if i<=target:
                dp[i].append([i])
#如7=5+2，而5=2+3等等，就可以递推出dp[i]
        for i in range(1,target+1):
            for j in range(1,i):
                if j in candidates:
                    for k in dp[i-j]:
                        tmp=k[:]
                        tmp.append(j)
                        tmp.sort()
                        if tmp not in dp[i]:
                            dp[i].append(tmp)
        #print(dp)
        return dp[-1]
```