### 解题思路
必须从后往前 因为从前往后没法知道什么时候“断”

然后依照从后往前 维护一个数组
如果i 比 i+1小 那么就是升序
dp[i]=dp[i+1]+1
不然的话就重置为1

然后nums和dp数组都加了一位
是为了“镶边”
好处理边界 不想加if else

### 代码

```python3
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        l=len(nums)
        dp=[0]*(l+1)
        nums+=[float("inf")]
        for i in range(l-1,-1,-1) :
            if nums[i]<nums[i+1] :
                dp[i]=dp[i+1]+1
            else :
                dp[i]=1
        return max(dp)


```