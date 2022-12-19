### 解题思路
动态规划 （dp[i] = max( dp[i-1] + 0, dp[i-2]+ num[i]) ）
因为不能接受相邻预约请求，所以需要跳着接跳比较目前状态 i是 sum(i)+a[i+2]大还是sum(i)+a[i+3]大

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        length = len(nums)
        dp =[0]*length
        if length==0:
            return 0
        elif length ==1:
            return nums[0]
        else:
            dp[0]=nums[0]
            dp[1]=max(nums[0],nums[1])
            i =2
            while i <length:
                dp[i] = max(dp[i-1],dp[i-2]+nums[i])
                #print(dp[i])
                i +=1
            return dp[length-1]
```