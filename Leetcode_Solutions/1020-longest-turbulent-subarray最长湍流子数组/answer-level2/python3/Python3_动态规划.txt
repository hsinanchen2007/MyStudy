### 解题思路
dp状态定义为：
    1.dp[0][i]:以第i个元素结尾，并且第i个元素是**上升**的湍流子数组的长度；
    2.dp[1][i]:以第i个元素结尾，并且第i个元素是**下降**的湍流子数组的长度；
状态转移为：
    - 如果A[i]>A[i-1],说明结尾是上升的，因此dp[0][i]=dp[1][i-1]+1,由以前一个数下降的子数组加一得到，并且dp[1][i]=1,即不可能以第i个数下降。当A[i]<A[i+1]时同理。
    - 
```
if A[i]>A[i-1]:
    dp[0][i]=dp[1][i-1]+1
    dp[1][i]=1
    maxLen=max(maxLen, dp[0][i])
elif A[i]<A[i-1]:
    dp[0][i]=1
    dp[1][i]=dp[0][i-1]+1
    maxLen=max(maxLen, dp[1][i])
```
### 代码

```python3
class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        size=len(A)
        if size<=1:
            return 1
        dp=[[1]*size for _ in range(2)]
        maxLen=1
        for i in range(1,size):
            if A[i]>A[i-1]:
                dp[0][i]=dp[1][i-1]+1
                dp[1][i]=1
                maxLen=max(maxLen, dp[0][i])
            elif A[i]<A[i-1]:
                dp[0][i]=1
                dp[1][i]=dp[0][i-1]+1
                maxLen=max(maxLen, dp[1][i])
        return maxLen




```